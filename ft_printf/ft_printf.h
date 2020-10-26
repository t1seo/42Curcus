/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:42 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 14:27:17 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
** type : format type
** width : width of field
** star :
** minus : left align
** zero : filled zeros if right align
** dot : precision
*/

typedef struct      s_arg_info
{
    char            flag;
    int             width;
    int             precision;
    char            specifier;
    char            *data;
}                   t_arg_info;

extern char	*g_format_type;

int		ft_printf(const char *format, ...);

#endif