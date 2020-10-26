/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:42 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 21:49:32 by tseo             ###   ########.fr       */
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
int		parsing_format(const char **ptr, t_va_info *info, va_list *ap);

#endif