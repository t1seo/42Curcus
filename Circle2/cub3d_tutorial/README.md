# cub3D Tutorial

## Project Overview

This folder contains tutorials and practice code studied to complete the cub3D project.

## Structure

```
cub3d_tutorial/
├── 01_math_library_tutorial/   # Math library study
├── 02_error/                   # Error handling study
├── 03_mlx_tutorial/            # MiniLibX study
│   ├── 01_open_window/         # Opening window
│   ├── 02_key_handling/        # Key input handling
│   ├── 03_image_loading/       # Image loading
│   ├── 04_image_making/        # Image creation
│   ├── 05_img_loading_and_modifying/  # Image modification
│   └── 06_2d_map/              # 2D map rendering
└── pikuma_tutorial/            # Pikuma course materials
```

## Study Topics

### 1. MiniLibX Basics

#### Window Creation
```c
void *mlx_ptr = mlx_init();
void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Title");
mlx_loop(mlx_ptr);
```

#### Key Event Handling
```c
mlx_hook(win_ptr, 2, 0, key_press_handler, &data);   // Key press
mlx_hook(win_ptr, 3, 0, key_release_handler, &data); // Key release
mlx_hook(win_ptr, 17, 0, close_handler, &data);      // Window close
```

#### Image Handling
```c
// Create image
void *img = mlx_new_image(mlx_ptr, width, height);
int *data = (int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);

// Load XPM file
void *img = mlx_xpm_file_to_image(mlx_ptr, "texture.xpm", &width, &height);
```

### 2. Raycasting Mathematics

#### Vector Operations
- Direction vector rotation
- Camera plane calculation
- Ray direction calculation

#### DDA Algorithm
- Grid-based ray tracing
- Wall intersection calculation

### 3. Rendering Pipeline

1. Calculate ray for each screen column
2. Detect wall collision with DDA
3. Calculate height from distance to wall
4. Calculate texture coordinates
5. Draw pixels

## Build (In each tutorial folder)

```bash
make
./program
```

## References

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Pikuma Raycasting Course](https://pikuma.com/)
- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/)
