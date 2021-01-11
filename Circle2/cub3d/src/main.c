/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:30:45 by tseo              #+#    #+#             */
/*   Updated: 2021/01/10 20:04:53 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel; // bits per pixel(bpp)
	int line_length;
	int endian;
} t_data;

// mlx_pixel_put 대신 버퍼에 담고 한ㄱ한꺼번에 출력 해주는 함수
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// color 입히기
	*(unsigned int *)dst = color;
}

// 피라미드 찍기
// x, y : 그릴 위치, size : 피라미드 크기, color : 색상
void print_pyramid(t_data *data, int x, int y, int size, int color)
{
	int num = size;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 2 * i + 1; j++)
			my_mlx_pixel_put(data, num - i + j + x, i + y, color);
}

int main(void)
{
	void *mlx;
	void *win;
	t_data img;

	mlx = mlx_init();							// 그래픽 시스템에 connection을 만든다.
	win = mlx_new_window(mlx, 640, 480, "MLX"); // 윈도우 생성
	img.img = mlx_new_image(mlx, 640, 480);		// 이미지를 만들었다.

	// 이미지를 만들었다면 mlx_get_data_addr을 불러올 수 있다.
	// 이미지에 픽셀을 그리기 위해 메모리 주소를 가져와야 한다.
	// bits_per_pexel, line_legnth, endain의 주소를 보낸다.
	// 항상 이 함수를 통해 set된 line_length를 가지고 메모리 주소 출발점 (offset)을 계산해야 한다.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// 픽셀 찍기
	print_pyramid(&img, 100, 100, 100, 0x000000FF);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0); // 이미지를 윈도우에 올린다.
	mlx_loop(mlx);

	return (0);
}
