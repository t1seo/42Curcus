#include "../include/mlx.h"
#include <stdio.h>

void    key_hook(int keycode, int *p_cnt)
{
    *p_cnt += 1;
    printf("key_hook...%d - %d\n", keycode, *p_cnt);

}

int     main(void)
{
    int     cnt;
    void    *mlx;
    void    *win;

    cnt = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "hooks");
    mlx_key_hook(win, &key_hook, &cnt);
    mlx_loop(mlx);
    return (0);
}

