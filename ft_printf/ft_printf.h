/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:42 by tseo              #+#    #+#             */
/*   Updated: 2020/10/27 19:32:28 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct      s_va_info
{
    char            flag;
    int             width;
    int             precision;
    char            specifier;
    char            *va_data;
}                   t_va_info;

extern char	*g_format_type;

int		ft_printf(const char *format, ...);

void		parsing_flag(const char **ptr, t_va_info *info);
void		parsing_width(const char **ptr, t_va_info *info, va_list *ap);
void		parsing_precision(const char **ptr, t_va_info *info, va_list *ap);
int         parsing_specifier(const char **ptr, t_va_info *info);

int     allocate_char_data(t_va_info *info, va_list *ap);
int     allocate_str_data(t_va_info *info, va_list *ap);
int     allocate_pointer_data(t_va_info *info, va_list *ap);
int     allocate_hex_lower(t_va_info *info, va_list *ap);
int     allocate_hex_upper(t_va_info *info, va_list *ap);
int     allocate_signed_int(t_va_info *info, va_list *ap);
int     allocate_unsigned_int(t_va_info *info, va_list *ap);
int     allocate_percent(t_va_info *info, va_list *ap);

void reset_info(t_va_info *info);
char	*ft_itoa_hex(unsigned int value);

#endif