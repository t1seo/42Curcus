# cub3D

## Project Overview

cub3D is a project to implement a 3D graphics engine using raycasting technique, inspired by Wolfenstein 3D. It creates a first-person perspective maze game using the MiniLibX graphics library.

## Core Concepts

### Raycasting
A technique that creates 3D effects by casting rays from a 2D map for each screen column and calculating intersection points with walls.

### DDA Algorithm (Digital Differential Analyzer)
An algorithm that traces along the grid until the ray hits a wall.

## Features

- First-person 3D rendering
- Texture mapping (North/South/East/West walls)
- Sprite rendering
- Player movement and rotation
- .cub map file parsing
- BMP screenshot saving (--save option)

## Controls

| Key | Action |
|-----|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Exit |

## Map File Format (.cub)

```
R 1920 1080                    # Resolution
NO ./textures/north.xpm        # North wall texture
SO ./textures/south.xpm        # South wall texture
WE ./textures/west.xpm         # West wall texture
EA ./textures/east.xpm         # East wall texture
S ./textures/sprite.xpm        # Sprite texture
F 220,100,0                    # Floor color (RGB)
C 225,30,0                     # Ceiling color (RGB)

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

Map Elements:
- `0`: Empty space
- `1`: Wall
- `2`: Sprite
- `N/S/E/W`: Player starting position and direction

## Structure

```
cub3d/
├── Makefile
├── inc/
│   └── cub3d.h              # Header file
├── src/
│   ├── main.c               # Main function
│   ├── parsing_*.c          # Map file parsing
│   ├── map_validation.c     # Map validation
│   ├── wall_casting.c       # Wall rendering
│   ├── sprite_casting.c     # Sprite rendering
│   ├── drawing.c            # Screen drawing
│   ├── key_handling.c       # Key input handling
│   ├── player_moving.c      # Player movement
│   └── saving_bmp.c         # BMP saving
├── libft/                   # libft library
├── mlx/                     # MiniLibX library
├── maps/                    # Map files
└── textures/                # Texture files
```

## Core Structures

```c
typedef struct s_player_info
{
    double  pos_x;        // Player X position
    double  pos_y;        // Player Y position
    double  dir_x;        // Direction vector X
    double  dir_y;        // Direction vector Y
    double  plane_x;      // Camera plane X
    double  plane_y;      // Camera plane Y
    int     **texture;    // Texture data
    int     **world_map;  // Map data
    double  *z_buffer;    // Depth buffer (for sprites)
}   t_player_info;

typedef struct s_wall_casting_info
{
    double  ray_dir_x;        // Ray direction X
    double  ray_dir_y;        // Ray direction Y
    double  perp_wall_dist;   // Perpendicular distance to wall
    int     side;             // Wall side (0: X-axis, 1: Y-axis)
    int     line_height;      // Line height to draw
    int     draw_start;       // Draw start Y coordinate
    int     draw_end;         // Draw end Y coordinate
}   t_wall_casting_info;
```

## Build

```bash
make        # Generate cub3D executable
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild
```

## Run

```bash
./cub3D maps/map.cub           # Normal execution
./cub3D maps/map.cub --save    # Save first frame as BMP
```

## Dependencies

- MiniLibX (mlx)
- libft
- math library (-lm)

## References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- Wolfenstein 3D (1992)
