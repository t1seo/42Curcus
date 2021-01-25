/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:35:46 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 13:27:50 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_error_and_exit(char *error_msg)
{
	printf("Error : %s\n", error_msg);
	exit(0);
}


void	print_parsing_error(char *error_msg, int fd)
{
	printf("Error : %s\n", error_msg);
	close(fd);
	exit(0);
}
