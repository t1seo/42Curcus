/*
** 1. untextured raycast
** verLine() 함수를 이용하여 픽셀별로 이미지를 그려낸다
*/
#include "./include/mlx.h"
#include "./include/key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480

typedef struct	s_info
{
	// 플레이어 초기 위치 벡터
	double posX;
	double posY;
	// 플레이어의 초기 방향 벡터
	double dirX;
	double dirY;
	// 카메라 플레인
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	calc(t_info *info)
{
	int	x;

	x = 0;
	// 이 반복문은 계속 반복해서 전체 프레임을 그려내고 입력을 읽는 일을 한다
	while (x < width)
	{
		// cameraX : 카메라 평면 내에서 x좌표
		double cameraX = 2 * x / (double)width - 1;
		// rayDirX, rayDirY는 광선의 방향벡터이다.
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;

		// 플레이어가 맵에서 어떤 박스에 있나
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		// 현재 위치에서 맵의 다음 x면 y면까지의 거리
		double sideDistX;
		double sideDistY;

		// x면에서 다음 x면, y면에서 다음 y면까지의 거리
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		// 어안효과 방지를 위한 수직 거리
		double perpWallDist;

		// DDA 알고리즘에 사용되는 변수들
		// 광선의 방향에 따라 어느 방향으로 건너뛰는지 달라지는데 그 정보가
		// stepX, stepY에 +1 또는 -1로 저장된다.
		int stepX;
		int stepY;

		int hit = 0; // 루프 종료 조건 : 벽에 부딪쳤는지 여부
		int side; // 벽에 부딪혔고 그게 x면이라면 0, y면이라면 1

		// step과 sideDist(현재 위치에서 다음 면까지 거리)의 계산
		if (rayDirX < 0)
		{
			stepX = -1; // rayDirX가 음수이면 stepX는 -1
			// rayDirX가 음수일 경우 광선 시작점부터 왼쪽으로 이동하다 처음 만나는 x면까지의 거리
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1; // rayDirX가 양수라면 stepY는 +1
			// rayDirX의 값이 양수일 경우 광선의 시작점부터 오른쪽으로 이동하다 처음 만나는 x면까지의 거리
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1; // rayDirY가 음수라면 stepY는 -1
			// rayDirY의 값이 음수일 경우 광선의 시작점부터 아래쪽으로 이동하다 처음 만나는 y면까지의 거리
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1; // rayDirY가 양수라면 stepY는 +1
			// rayDirY의 값이 양수일 경우 광선의 시작점부터 위쪽으로 이동하다 처음 만나는 y면까지의 거리
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		// DDA 알고리즘 수행 : 벽에 부딪힐 때까지 매번 한 칸(square)씩 광선을 이동시킨다.
		while (hit == 0)
		{
			// x방향으로 한 칸 점프
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX; // sideDistX(현재 위치에서 다음 x면까지의 거리)값 업데이트
				mapX += stepX;
				side = 0; // 벽의 x면과 부딪혔다
			}
			// y방향으로 한 칸 점프
			else
			{
				sideDistY += deltaDistY; // sideDistY(현재 위치에서 다음 y면까지의 거리)값 업데이트
				mapY += stepY;
				side = 1; // 벽의 y면과 부딪혔다
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		// 어안효과를 피하기 위해 충돌 지점부터 카메라 평면에 수직인 직선 거리를 구한다
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		// 그려야 할 벽의 높이를 perpWallDist의 역수를 이용해서 구한다(수직거리의 반비례)
		int lineHeight = (int)(height / perpWallDist);

		// 그려야 할 벽의 시작지점과 끝지점의 위치를 구한다
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		// 광선이 부딪힌 벽의 색상 값에 따라 표현할 색상을 선택해준다
		int	color;
		if (worldMap[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (worldMap[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (worldMap[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (worldMap[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		// x면이냐 y면이냐에 따라 밝기 다르게 해준다
		if (side == 1)
			color = color / 2;

		// 수직 벽을 그려준다
		// x: 충돌지점, drawStart: 벽시작 위치, drawEnd: 벽끝나는 지점, color: 색
		verLine(info, x, drawStart, drawEnd, color);

		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

	return (0);
}

int	key_press(int key, t_info *info)
{
	// 앞에 벽이 없으면 앞으로 간다
	if (key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	// 뒤에 벽이 없으면 뒤로 간다
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	// 우측으로 회전
	if (key == K_D)
	{
		// 방향 벡터와 카메라 평면이 동시에 회전해애 한다
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	// 좌측으로 회전
	if (key == K_A)
	{
		// 방향 벡터와 카메라 평면이 동시에 회전해애 한다
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	// 플레이어의 초기 위치 벡터
	info.posX = 12;
	info.posY = 5;
	// 플레이어의 초기 방향 벡터
	info.dirX = -1;
	info.dirY = 0;
	// 플레이어의 카메라 평면
	info.planeX = 0;
	info.planeY = 0.66;
	// 플레이어 이동 속도와 회전 속도
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;

	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}
