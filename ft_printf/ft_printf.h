/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:42 by tseo              #+#    #+#             */
/*   Updated: 2020/10/25 02:11:52 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

/*
** type : format type
** width : width of field
** star :
** minus : left align
** zero : filled zeros if right align
** dot : precision
*/

typedef struct      s_format_info
{
    char type;
    int width;
    int minus;
    int zero;
    int dot;
    int star;
}                   t_format_info;

const char    *g_format_type = "cspdiuoxX";

int		ft_printf(const char *format, ...);

#endif