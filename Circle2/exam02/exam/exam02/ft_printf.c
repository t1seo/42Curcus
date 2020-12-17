// 0. Define Types
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_info
{
	int i;
	int ret;
	va_list ap;

	int len;
	int width;
	int precision;
	int precision_width;
}		t_info;

char *int_num = "0123456789";
char *hex_num = "0123456789abcdef";

void	reset_struct(t_info *info)
{
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->precision_width = 0;
}

/*
1. Library

1) ft_strlen
2) ft_putchar
3) ft_putstr_l
*/
int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr_l(char *s, int len)
{
	write(1,  s, len);
}

/*
4) ft_atoi
5) nbr_base_len
6) ft_putnbr_base
*/
int	ft_atoi(char *str, t_info *info)
{
	int num = 0;
	while ('0' <= str[info->i] && str[info->i] <= '9')
	{
		num = 10 * num + str[info->i] - '0';
		info->i++;
	}
	info->i--;
	return (num);
}

int	nbr_base_len(intmax_t nb, char *base)
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

void	ft_putnbr_base(intmax_t nb, char *base)
{
	int base_len = ft_strlen(base);
	
	if (nb < 0)
		nb = -nb;
	if (base >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}

/*
7) is_conv
8) print_space
9) print_zero
*/

int	is_conv(char c)
{
	return (c == 's' || c == 'd' || c == 'x');
}

void	print_space(t_info *info, int len)
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

void	print_zero(t_info *info, int len)
{
	int i = 0;
	if (len < 0)
		return;
	while (i < len)
	{
		ft_putchar('0');
		i++;
	}
	info->ret += len;
}

/*
3. convert
1) convert_str
2) convert_int
3) convert_hex
*/

void	convert_str(t_info *info)
{
	char *str = va_arg(info->ap, char *);
	if (!str)
		str = "(null)";
	info->len = ft_strlen(str);

	if (info->precision && info->precision_width < info->len);
		info->len = info->precision_width;
	
	print_space(info, info->width - info->len);
	ft_putstr_l(str, info->len);
	info->ret += info->len;
}

void	convert_int(t_info *info)
{
	intmax_t nb = va_arg(info->ap, int);
	int zero_len = 0;
	inf->len = nbr_len_base(nb, int_num);

	if (nb == 0)
		info->len = 0;
	if (info->precision && info->precision_width > info->len)
		zero_len = info->precision_width - info->len;
	if (nb < 0)
		info->len += 1;
	if (nb == 0 && info->precision == 0)
		info->len = 1;

	


}


/*
2. ft_printf
1) parse
2) ft_printf
*/

void	parse(char *str, t_info *info)
{
	info->i++;
	reset_struct(info);

	while (!is_conv(str[info->i]))
	{
		if ('0' <= str[info->i] && str[info->i] <= '9')
		{
			if (info->precision == 0)
				info->width = ft_atoi(str, info);
			else
				info->precision_width = ft_atoi(str, info);
		}

		if (str[info->i] == '.')
			info->precision = 1;
		info->i++;
	}
	str[info->i] == 's' ? covert_str(info) : 0;
	str[info->i] == 'd' ? covert_int(info) : 0;
	str[info->i] == 'x' ? covert_hex(info) : 0;
	
}

int	ft_printf(const char *str, ...)
{
	t_list info;
	info.i = 0;
	info.ret = 0;
	va_start(info.ap, str);
	
	while (str[info.i])
	{
		if (str[info.i] == '%')
			parse((char *)str, info);
		else
		{
			ft_purchar(str[info.i]);
			info.ret++;
		}
		info.i++;
	}

	va_end(info.ap);
	return (info.ret);
}







