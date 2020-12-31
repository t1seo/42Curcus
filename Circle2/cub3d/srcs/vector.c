/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 20:41:22 by tseo              #+#    #+#             */
/*   Updated: 2020/12/31 20:45:48 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

double			get_radian(int num)
{
	return num * (PI / 100);
}

t_dvec			create_dvec(double x, double y)
{
	t_dvec	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_ivec			create_ivec(int x, int y)
{
	t_ivec	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_dvec			rotate_dvec(t_dvec a, double angle)
{
	double	sin_angle;
	double	cos_angle;
	t_dvec	result;

	sin_angle = sin(get_radian(angle));
	cos_angle = cos(get_radian(angle));
	result.x = cos_angle * a.x - sin_angle * a.y;
	result.y = sin_angle * a.x + cos_angle * a.y;
	return (result);
}
