/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:44:56 by tseo              #+#    #+#             */
/*   Updated: 2021/01/20 19:57:17 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		*g_sprite_order;
double	*g_sprite_distance;

static int		compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

void			sort_order(t_pair *orders, int num_of_sprites)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < num_of_sprites)
	{
		j = -1;
		while (++j < num_of_sprites - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp = orders[j];
				orders[j] = orders[j + 1];
				orders[j + 1] = tmp;
			}
		}
	}
}

void			sort_sprites(int *order, double *dist, int num_of_sprites)
{
	t_pair	*sprites;
	int		i;

	if (!(sprites = (t_pair *)malloc(sizeof(t_pair) * num_of_sprites)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	while (++i < num_of_sprites)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, num_of_sprites);
	i = -1;
	while (++i < num_of_sprites)
	{
		dist[i] = sprites[num_of_sprites - i - 1].first;
		order[i] = sprites[num_of_sprites - i - 1].second;
	}
	free(sprites);
}

// /*
// ** Sort sprites from far to close
// */
// void	sort_sprites_from_far_to_close(t_player_info *p_info)
// {
// 	int i;

// 	if (!(g_sprite_order = (int *)malloc(sizeof(int) * (NUM_OF_SPRITES))))
// 	{
// 		printf("Error : Memory Allocation Failed.\n");
// 		exit(0);
// 	}
// 	if (!(g_sprite_distance = (double *)malloc(sizeof(double) * (NUM_OF_SPRITES))))
// 	{
// 		printf("Error : Memory Allocation Failed.\n");
// 		exit(0);
// 	}
// 	i = -1;
// 	while (++i < NUM_OF_SPRITES)
// 	{
// 		g_sprite_order[i] = i;
// 		g_sprite_distance[i] = ((p_info->pos_x - g_sprite[i].x) * (p_info->pos_x - g_sprite[i].x)
// 		+ (p_info->pos_y - g_sprite[i].y) * (p_info->pos_y - g_sprite[i].y));
// 	}
// 	sort_sprites(g_sprite_order, g_sprite_distance, NUM_OF_SPRITES);
// 	printf("SORT SPRITES FROM FAR TO CLOSE.\n");
// }

// /*
// ** Translate sprite position to relative to camera
// */
// void	translate_sprite_position(t_sprite_info *s_info, t_player_info *p_info, int i)
// {
// 	s_info->sprite_x = g_sprite[g_sprite_order[i]].x - p_info->pos_x;
// 	s_info->sprite_y = g_sprite[g_sprite_order[i]].y - p_info->pos_y;
// 	printf("TRANSLATE SPRITE POSITION\n");
// }


// /*
// ** Transform sprite with the inverse camera matrix
// */
// void	transform_sprite(t_sprite_info *s_info, t_player_info *p_info)
// {
// 	s_info->inv_det = 1.0 / (p_info->plane_x * p_info->dir_y - p_info->dir_x * p_info->plane_y);
// 	s_info->transform_x = s_info->inv_det * (p_info->dir_y * s_info->sprite_x - p_info->dir_x * s_info->sprite_y);
// 	s_info->transform_y = s_info->inv_det * (-p_info->plane_y * s_info->sprite_x + p_info->plane_x * s_info->sprite_y);
// 	s_info->sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1 + s_info->transform_x / s_info->transform_y));
// 	printf("TRANSFORM SPRITE\n");
// }

// void	calc_scaling_moving_parameter(t_sprite_info *s_info)
// {
// 	s_info->v_move_screen = (int)(V_MOVE / s_info->transform_y);
// 	printf("V MOVE\n");
// }

// void	calc_draw_sprite_pos(t_sprite_info *s_info)
// {
// 	s_info->sprite_height = (int)fabs((SCREEN_HEIGHT / s_info->transform_y) / V_DIV);
// 	s_info->draw_start_y = -s_info->sprite_height / 2 + SCREEN_HEIGHT / 2 + s_info->v_move_screen;
// 	if (s_info->draw_start_y < 0)
// 		s_info->draw_start_y = 0;
// 	s_info->draw_end_y = s_info->sprite_height / 2 + SCREEN_HEIGHT / 2 + s_info->v_move_screen;
// 	if (s_info->draw_end_y >= SCREEN_HEIGHT)
// 		s_info->draw_end_y = SCREEN_HEIGHT - 1;
// 	s_info->sprite_width = (int)fabs((SCREEN_HEIGHT / s_info->transform_y) / U_DIV);
// 	s_info->draw_start_x = -s_info->sprite_width / 2 + s_info->sprite_screen_x;
// 	if (s_info->draw_start_x < 0)
// 		s_info->draw_start_x = 0;
// 	s_info->draw_end_x = s_info->sprite_width / 2 + s_info->sprite_screen_x;
// 	if (s_info->draw_end_x >= SCREEN_WIDTH)
// 		s_info->draw_end_x = SCREEN_WIDTH - 1;
// 	printf("CALCULATE SPRITE HEIGHT AND WIDTH\n");
// }

// void	draw_sprite(t_sprite_info *s_info, t_player_info *p_info, int i)
// {
// 	int x;
// 	int tex_x;
// 	int y;
// 	int d;
// 	int tex_y;
// 	int color;

// 	x = s_info->draw_start_x;
// 	while (x < s_info->draw_end_x)
// 	{
// 		tex_x = (int)((256 * (x - (-s_info->sprite_width / 2 + s_info->sprite_screen_x)) * TEX_WIDTH / s_info->sprite_width) / 256);
// 		if (s_info->transform_y > 0 && x > 0 && x < SCREEN_WIDTH && s_info->transform_y < p_info->z_buffer[x])
// 		{
// 			y = s_info->draw_start_y;
// 			while (y < s_info->draw_end_y)
// 			{
// 				d = (y - s_info->v_move_screen) * 256 - SCREEN_HEIGHT * 128 + s_info->sprite_height * 128;
// 				tex_y = ((d * TEX_HEIGHT) / s_info->sprite_height) / 256;
// 				color = p_info->texture[4][TEX_WIDTH * tex_y + tex_x];
// 				// printf("ERROR\n");
// 				printf("%d\n", color);
// 				if ((color & 0x00FFFFFF) != 0)
// 					p_info->buf[y][i] = color;
// 				y++;
// 			}
// 		}
// 		x++;
// 	}
// 	printf("DRAW SPRITE\n");
// }

void	sprite_casting(t_player_info *p_info)
{
	int i;
	t_sprite_info	s_info;

	// sort_sprites_from_far_to_close(p_info);
	// printf("SPRITE CASTING\n");
	// i = -1;
	// while (++i < NUM_OF_SPRITES)
	// {
	// 	translate_sprite_position(&s_info, p_info, i);
	// 	transform_sprite(&s_info, p_info);
	// 	calc_scaling_moving_parameter(&s_info);
	// 	calc_draw_sprite_pos(&s_info);
	// 	draw_sprite(&s_info, p_info, i);
	// }

	// SPRITE CASTING
	//sort sprites from far to close
	if (!(g_sprite_order = (int *)malloc(sizeof(int) * (NUM_OF_SPRITES))))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	if (!(g_sprite_distance = (double *)malloc(sizeof(double) * (NUM_OF_SPRITES))))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	for(int i = 0; i < NUM_OF_SPRITES; i++)
	{
		g_sprite_order[i] = i;
		g_sprite_distance[i] = ((p_info->pos_x - g_sprite[i].x) * (p_info->pos_x - g_sprite[i].x) +
		(p_info->pos_y - g_sprite[i].y) * (p_info->pos_y - g_sprite[i].y)); //sqrt not taken, unneeded
	}
	sort_sprites(g_sprite_order, g_sprite_distance, NUM_OF_SPRITES);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < NUM_OF_SPRITES; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = g_sprite[g_sprite_order[i]].x - p_info->pos_x;
		double spriteY = g_sprite[g_sprite_order[i]].y - p_info->pos_y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (p_info->plane_x * p_info->dir_y - p_info->dir_x * p_info->plane_y); //required for correct matrix multiplication

		double transformX = invDet * (p_info->dir_y * spriteX - p_info->dir_x * spriteY);
		double transformY = invDet * (-p_info->plane_y * spriteX + p_info->plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((SCREEN_WIDTH / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((SCREEN_HEIGHT / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + SCREEN_HEIGHT / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + SCREEN_HEIGHT / 2 + vMoveScreen;
		if(drawEndY >= SCREEN_HEIGHT) drawEndY = SCREEN_HEIGHT - 1;

		//calculate width of the sprite
		int spriteWidth = (int)fabs((SCREEN_HEIGHT / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= SCREEN_WIDTH) drawEndX = SCREEN_WIDTH - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * TEX_WIDTH / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < SCREEN_WIDTH && transformY < p_info->z_buffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - SCREEN_HEIGHT * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * TEX_HEIGHT) / spriteHeight) / 256;
				int color = p_info->texture[g_sprite[g_sprite_order[i]].texture][TEX_WIDTH * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0) p_info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
}
