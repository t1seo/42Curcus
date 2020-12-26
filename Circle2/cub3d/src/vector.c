/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:44:59 by tseo              #+#    #+#             */
/*   Updated: 2020/12/26 23:45:25 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

double	get_radian(double angle)
{
	return (angle * (PI / 180.0));
}

t_vec	vec_new(double x, double y)
{
	t_vec result;

	result.x = x;
	result.y = y;
	return (result);
}

t_int_vec int_vet_new(int x, int y)
{
	t_int_vec result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vec	vec_rotation(t_vec a, double angle)
{
	double	sin_angle;
	double	cos_angle;
	t_vec	result;

	sin_angle = sin(get_radian(angle));
	cos_angle = cos(get_radian(angle));
	result.x = cos_angle * a.x - sin_angle * a.y;
	result.y = sin_angle * a.x + cos_angle * a.y;
	return (result);
}
