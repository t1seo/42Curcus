/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:10:40 by tseo              #+#    #+#             */
/*   Updated: 2020/12/26 23:51:53 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# define PI 3.1415926535897

typedef struct	s_vec
{
	double x;
	double y;
}				t_vec;

typedef struct	s_int_vec
{
	int x;
	int y;
}				t_int_vec;


double	get_radian(double angle);
t_vec	vec_new(double x, double y);
t_int_vec int_vet_new(int x, int y);
t_vec	vec_rotation(t_vec a, double angle);

#endif
