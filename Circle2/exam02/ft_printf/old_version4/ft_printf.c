#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// 0. Define Data Types
typedef struct s_info
{
	va_list ap;
	int i;
	int ret;

	int len;
	int width;
	int precision;
	int precision_width;
	int precision_parsing;
} t_info;

void reset_struct(t_info *info)
{
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->precision_width = 0;
	info->precision_parsing = 0;
}

char *int_num = "0123456789";
char *hex_num = "0123456789abcdef";

// 4-1 Library - string
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void ft_putstr_len(char *s, int len)
{
	write(1, s, len);
}

// 4-2 Library - nbr
int nbr_len_base(intmax_t nb, char *base)
{
	int len = 1;
	int base_len = ft_strlen(base);

	if (nb < 0)
		nb = -nb;
	while (nb >= base_len)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

void ft_putnbr_base(intmax_t nb, char *base)
{
	int base_len = ft_strlen(base);

	if (nb < 0)
		nb = -nb;
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}

int ft_atoi(char *str, t_info *info)
{
	int num = 0;
	while ('0' <= str[info->i] && str[info->i] <= '9')
	{
		num = num * 10 + str[info->i] - 48;
		info->i++;
	}
	info->i--;
	return (num);
}

// 4-3 Library - print
int is_conv(char c)
{
	return (c == 's' || c == 'x' || c == 'd');
}

void print_space(t_info *info, int len)
{
	int i = 0;

	if (len < 0)
		return;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	info->ret += len;
}

void print_zero(t_info *info, int len)
{
	int i = 0;

	if (len < 0)
		return;
	while (i < len)
	{
		ft_putchar('0');
	}
	info->ret += len;
}

// 3-1 convert_str
void convert_str(t_info *info)
{
	char *str = va_arg(info->ap, char *);
	if (!str)
		str = "(null)";
	info->len = ft_strlen(str);
	if (info->precision && info->precision_width < info->len)
		info->len = info->precision_width;
	print_space(info, info->width - info->len);
	ft_putstr_len(str, info->len);
	info->ret += info->len;
}

// 3-2 convert_int
void convert_int(t_info *info)
{
	intmax_t nb = va_arg(info->ap, int);
	int zero_len = 0;

	info->len = nbr_len_base(nb, int_num);
	if (nb == 0)
		info->len = 0;
	if (info->precision && info->precision_width > info->len)
		zero_len = info->precision_width - info->len;
	if (nb < 0)
		info->len += 1;
	if (nb == 0 && !info->precision)
		info->len = 1;
	print_space(info, info->width - (zero_len + info->len));
	if (nb < 0)
		ft_putchar('-');
	print_zero(info, zero_len);
	if (info->precision && nb == 0)
		return;
	ft_putnbr_base(nb, "0123456789");
	info->ret += info->len;
}

// 3-3 conver_hex
void convert_hex(t_info *info)
{
	intmax_t nb = va_arg(info->ap, unsigned int);
	int zero_len = 0;

	info->len = nbr_len_base(nb, hex_num);
	if (info->precision && info->precision_width > info->len)
		zero_len = info->precision - info->len;
	if (nb == 0 && info->precision == 1 && info->precision_width == 0)
		info->len = 0;
	print_space(info, info->width - (zero_len + info->len));
	print_zero(info, zero_len);
	if (info->precision && info->precision_width == 0 && nb == 0)
		return;
	ft_putnbr_base(nb, hex_num);
	info->ret += info->len;
}

// 2. parse
void parse(char *str, t_info *info)
{
	info->i++;
	reset_struct(info);

	while (!is_conv(str[info->i]))
	{
		if ('0' <= str[info->i] && str[info->i] <= '9')
		{
			if (info->precision_parsing)
				info->precision_width = ft_atoi(str, info);
			else
				info->width = ft_atoi(str, info);
		}
		// precision flags
		info->precision_parsing = 0;
		if (str[info->i] == '.')
		{
			info->precision = 1;
			info->precision_parsing = 1;
		}
		info->i++;
	}
	str[info->i] == 's' ? convert_str(info) : 0;
	str[info->i] == 'd' ? convert_int(info) : 0;
	str[info->i] == 'x' ? convert_hex(info) : 0;
}

// 1. ft_printf
int ft_printf(const char *str, ...)
{
	t_info info;

	info.i = 0;
	info.ret = 0;
	va_start(info.ap, str);

	while (str[info.i])
	{
		if (str[info.i] == '%')
			parse((char *)str, &info);
		else
		{
			ft_putchar(str[info.i]);
			info.ret++;
		}
		info.i++;
	}

	va_end(info.ap);
	return (info.ret);
}
