/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 20:01:06 by tseo              #+#    #+#             */
/*   Updated: 2021/01/10 20:02:21 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>

#define PI 3.1415926535897

typedef struct	s_dvec
{
	double 		x;
	double 		y;
}				t_dvec;

typedef struct	s_ivec
{
	int			x;
	int			y;
}				t_ivec;

double			get_radian(int num);
t_dvec			create_dvec(double x, double y);
t_ivec			create_ivec(int x, int y);
t_dvec			rotate_vec(t_dvec a, double angle);

#endif
