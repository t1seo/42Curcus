# define PI    3.14159265359

void    draw_dir_ray(t_game *game, double angle)
{
    double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;
    double    max_value;

    ray_x = game->pos.x;
    ray_y = game->pos.y;

    dx = cos(angle) * game->dir_vec.x - sin(angle) * game->dir_vec.y;
    dy = sin(angle) * game->dir_vec.x + cos(angle) * game->dir_vec.y;

    max_value = fmax(fabs(dx), fabs(dy));
    dx /= max_value;
    dy /= max_value;
    while (1)
    {
        if (game->map_img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] != 0x0000FF)
            game->map_img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] = 0xFF0000;
        else
            break;
        ray_x += dx;
        ray_y += dy;
    }
}

void    draw_ray(t_game *game)
{
    double angle;

    angle = 0;
    while (angle < PI/6)
    {
        draw_dir_ray(game, angle);
        draw_dir_ray(game, -angle);
        angle += PI/72;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->map_img.img, 0, 0);
}

void    rotate_matrix(t_vec2 *vec, double angle)
{
    double    tmp_x;

    tmp_x = cos(angle) * vec->x - sin(angle) * vec->y;
    vec->y = sin(angle) * vec->x + cos(angle) * vec->y;
    vec->x = tmp_x;
}

int        key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit(0);
    if (keycode == KEY_LEFT)
        rotate_matrix(&game->dir_vec, PI/36);
    if (keycode == KEY_RIGHT)
        rotate_matrix(&game->dir_vec, -PI/36);
    return (0);
}
