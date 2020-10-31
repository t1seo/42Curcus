/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:50:48 by heryu             #+#    #+#             */
/*   Updated: 2020/10/26 21:07:56 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../lib/libft.h"

#define RET_ERROR -1
#define RET_SUCCESS 1
#define ALLOC_ERROR 0

typedef struct	s_print_info
{
	char		flag;
	int			width;
	int			precision;
	char		specifier;
	char		*data;
}				t_print_info;

int				ft_printf(const char *str, ...);

char			*ft_itoa_unsigned(unsigned int n);
char			get_hex_char_lowercase(int n);
char			*ft_itoa_base_unsigned_hex_ul(unsigned long val);
char			*ft_itoa_base_unsigned_hex(unsigned int val);

int				parsing_flags(const char *str, t_print_info *info, va_list *ap);

int				make_print_data(t_print_info *info, va_list *ap);
int				make_print_data_char(t_print_info *info, va_list *ap);
int				make_print_data_string(t_print_info *info, va_list *ap);
int				make_print_data_percent(t_print_info *info);
int				make_print_data_pointer(t_print_info *info, va_list *ap);
int				make_print_data_hex_lowercase(t_print_info *info, va_list *ap);
int				make_print_data_hex_uppercase(t_print_info *info, va_list *ap);
int				make_print_data_signed_int(t_print_info *info, va_list *ap);
int				make_print_data_unsigned_int(t_print_info *info, va_list *ap);

int				print_data(t_print_info *info);
int				write_padding(char padding_char, int cnt);
int				print_data_char(t_print_info *info);
int				print_data_string(t_print_info *info);
int				print_data_pointer(t_print_info *info);
int				print_data_percent(t_print_info *info);
int				print_data_integer(t_print_info *info);

void			init_info(t_print_info *info);
int				print_data_and_free(t_print_info *info);

#endif
