#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17

/*
**  MINI_MAP
*/
#define TILE_SIZE 32
#define MAP_NUM_ROWS 24
#define MAP_NUM_COLS 24
#define WINDOW_WIDTH ((MAP_NUM_COLS) * (TILE_SIZE))
#define WINDOW_HEIGHT ((MAP_NUM_ROWS) * (TILE_SIZE))

#define BACKGROUND_COLOR 0x555555
#define BORDER_COLOR 0xffffff
#define WALL_COLOR 0x222222


/*
** SCREEN_SIZE
*/
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/*
** KEY_MACOS
*/
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_ESC 53

/*
** pos_x, pos_y :
** dir_x, dir_y :
** plane_x, plane_y :
** move_speed : move speed of the player
** rot_speed : rotation speed of the player
*/

typedef struct      s_player_info
{
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
    double move_speed;
    double rot_speed;
}                   t_player_info;


#endif
