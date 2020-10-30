/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:42 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 06:24:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_va_info
{
	char			flag;
	int				width;
	int				precision;
	char			specifier;
	char			*va_data;
}					t_va_info;

extern char const	*g_format_type;
extern char const	*g_hex_digits_lower;
extern char const	*g_hex_digits_upper;
extern char const	*g_int_digits;

int					ft_printf(const char *format, ...);

void				parsing_flag(const char **ptr, t_va_info *info);
void				parsing_width(const char **ptr,
								t_va_info *info, va_list *ap);
void				parsing_precision(const char **ptr,
								t_va_info *info, va_list *ap);
int					parsing_specifier(const char **ptr, t_va_info *info);

int					allocate_char_data(t_va_info *info, va_list *ap);
int					allocate_str_data(t_va_info *info, va_list *ap);
int					allocate_pointer_data(t_va_info *info, va_list *ap);
int					allocate_signed_int(t_va_info *info, va_list *ap);
int					allocate_unsigned_int(t_va_info *info, va_list *ap);
int					allocate_hex(t_va_info *info, va_list *ap);
int					allocate_percent(t_va_info *info);

void				reset_info(t_va_info *info);
char				*ft_itoa_base(unsigned long int value, char const *base);
int					get_max(int a, int b);
void				handling_width_util(t_va_info *info,
									char *parsed_data, int len, int r_len);

void				ft_make_free(char *tmp, t_va_info *info);
void				print_char_data(t_va_info *info, int *count);

int					make_aligned(t_va_info *info);
int					make_aligned_char(t_va_info *info);
int					make_aligned_str(t_va_info *info);
int					make_aligned_percent(t_va_info *info);
int					make_aligned_ptr(t_va_info *info);
int					make_aligned_int(t_va_info *info);
int					make_aligned_uint(t_va_info *info);
int					make_aligned_hex(t_va_info *info);

#endif
