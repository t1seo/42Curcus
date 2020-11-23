#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_va_info
{
	char flag;
	int width;
	int precision;
	char specifier;
	char *va_data;
} t_va_info;

char const *g_format_type = "sdx";
char const *g_hex_digits_lower = "0123456789abcdef";
char const *g_int_digits = "0123456789";

/*
** libft
*/

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static int ft_abs(int n)
{
	return (n < 0) ? -n : n;
}

int ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int get_num_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

char *ft_strdup(const char *s)
{
	int i;
	char *ret;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

/*
** utils
*/

void reset_info(t_va_info *info)
{
	if (!(info->va_data))
		free(info->va_data);
	info->flag = 0;
	info->width = -1;
	info->precision = -1;
	info->specifier = 0;
	info->va_data = 0;
}

char *ft_itoa_base(unsigned long int value, char const *base)
{
	unsigned long int n;
	int i;
	char *ret;
	int len;

	len = ft_strlen(base);
	n = value;
	i = 0;
	while (n)
	{
		n /= len;
		++i;
	}
	n = value;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	while (n)
	{
		--i;
		ret[i] = base[n % len];
		n /= len;
	}
	return (ret);
}

void write_letters(char *str, int len, int *count)
{
	write(1, str, len);
	(*count) += len;
}

void write_padding(char padding, int size, int *count)
{
	if (padding == 0)
		padding = ' ';
	while (size > 0)
	{
		write(1, &padding, 1);
		(*count)++;
		size--;
	}
}

/*
** parsing_format
*/
void parsing_width(const char **ptr, t_va_info *info, va_list *ap)
{
	info->width = ft_atoi(*ptr);
	while (ft_isdigit(**ptr))
		(*ptr)++;
}

void parsing_precision(const char **ptr, t_va_info *info, va_list *ap)
{
	if (**ptr != '.')
	{
		info->precision = -1;
		return;
	}
	(*ptr)++;
	info->precision = ft_atoi(*ptr);
	while (ft_isdigit(**ptr))
		(*ptr)++;
}

int parsing_specifier(const char **ptr, t_va_info *info)
{
	const char *format_type;

	format_type = g_format_type;
	while (*format_type)
	{
		if (*format_type == **ptr)
		{
			info->specifier = *format_type;
			(*ptr)++;
			return (1);
		}
		format_type++;
	}
	return (0);
}

/*
** allocating data
*/

int allocate_str_data(t_va_info *info, va_list *ap)
{
	char *tmp;

	tmp = va_arg(*ap, char *);
	if (!tmp)
	{
		if (!(info->va_data = ft_strdup("(null)")))
			return (0);
		return (1);
	}
	if (!(info->va_data = ft_strdup(tmp)))
		return (0);
	return (1);
}

int allocate_signed_int(t_va_info *info, va_list *ap)
{
	int tmp;

	tmp = va_arg(*ap, int);
	if (tmp == 0 && info->precision == 0)
	{
		if (!(info->va_data = (char *)malloc(sizeof(char) * 1)))
			return (0);
		info->va_data[0] = 0;
	}
	else if (tmp == 0)
	{
		if (!(info->va_data = (char *)malloc(sizeof(char) * 2)))
			return (0);
		info->va_data[0] = '0';
		info->va_data[1] = 0;
	}
	else
	{
		if (!(info->va_data = ft_itoa_base(tmp, g_int_digits)))
			return (0);
	}
	return (1);
}

int allocate_hex(t_va_info *info, va_list *ap)
{
	unsigned int tmp;

	tmp = va_arg(*ap, unsigned int);
	if (tmp == 0)
	{
		if (!(info->va_data = (char *)malloc(sizeof(char) * 2)))
			return (0);
		info->va_data[0] = '0';
		info->va_data[1] = 0;
	}
	else if (info->specifier == 'x')
	{
		if (!(info->va_data = ft_itoa_base(tmp, g_hex_digits_lower)))
			return (0);
	}

	return (1);
}

/*
** printing data
*/

void print_str_data(t_va_info *info, int *count)
{
	int va_data_len;

	va_data_len = ft_strlen(info->va_data);
	if (info->precision != -1 && info->precision < va_data_len)
		va_data_len = info->precision;
	write_padding(' ', info->width - va_data_len, count);
	write_letters(info->va_data, va_data_len, count);
}

static void print_num_data_without_precision(t_va_info *info,
											 int va_data_len, int *count, int skip_sign_idx)
{
	write_padding(info->flag, info->width - va_data_len, count);
	write_letters(info->va_data, va_data_len, count);
}

static void print_num_data_with_precision(t_va_info *info, int va_data_len,
										  int *count, int skip_sign_idx)
{
	int rest_width_len;

	if (va_data_len > info->precision + skip_sign_idx)
		rest_width_len = info->width - va_data_len;
	else
		rest_width_len = info->width - (info->precision + skip_sign_idx);

	write_padding(' ', rest_width_len, count);
	write_letters(info->va_data, skip_sign_idx, count);
	write_padding('0',
				  info->precision - (va_data_len - skip_sign_idx), count);
	write_letters(info->va_data + skip_sign_idx,
				  va_data_len - skip_sign_idx, count);
}

void print_num_data(t_va_info *info, int *count)
{
	int va_data_len;
	int skip_sign_idx;

	va_data_len = ft_strlen(info->va_data);
	if (info->va_data[0] == '-')
		skip_sign_idx = 1;
	else
		skip_sign_idx = 0;
	if (info->precision == -1)
		print_num_data_without_precision(info, va_data_len,
										 count, skip_sign_idx);
	else
	{
		if (info->precision == 0 && info->va_data[0] == '0' && va_data_len == 1)
			va_data_len = 0;
		print_num_data_with_precision(info, va_data_len, count, skip_sign_idx);
	}
}

/*
** ft_printf
*/
static int parsing_format(const char **ptr, t_va_info *info, va_list *ap)
{
	(*ptr)++;
	parsing_width(ptr, info, ap);
	parsing_precision(ptr, info, ap);
	if (!(parsing_specifier(ptr, info)))
		return (0);
	return (1);
}

static int data_allocation(t_va_info *info, va_list *ap)
{
	if (info->specifier == 's')
		return (allocate_str_data(info, ap));
	if (info->specifier == 'd')
		return (allocate_signed_int(info, ap));
	if (info->specifier == 'x')
		return (allocate_hex(info, ap));
	return (1);
}

static void print_data(t_va_info *info, int *count)
{
	if (info->specifier == 's')
		print_str_data(info, count);
	if (info->specifier == 'd' || info->specifier == 'x')
		print_num_data(info, count);
}

static int init_format_parsing(const char *format, va_list *ap,
							   t_va_info *info)
{
	int count;

	count = 0;
	while (*format)
	{
		reset_info(info);
		if ((*format) == '%')
		{
			if (!(parsing_format(&format, info, ap)) || !(data_allocation(info, ap)))
			{
				count = -1;
				break;
			}
			print_data(info, &count);
			continue;
		}
		write(1, format++, 1);
		count++;
	}
	reset_info(info);
	free(info);
	return (count);
}

int ft_printf(const char *format, ...)
{
	int ret;
	va_list ap;
	t_va_info *info;

	if (!(info = (t_va_info *)malloc(sizeof(t_va_info))))
		return (-1);
	if (!ft_strlen(format))
		return (0);
	va_start(ap, format);
	ret = init_format_parsing(format, &ap, info);
	va_end(ap);
	return (ret);
}
