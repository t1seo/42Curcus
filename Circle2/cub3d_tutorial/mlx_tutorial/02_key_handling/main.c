#include <stdio.h>
#include <stdlib.h>
#include "../include/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17

// MAC KEY CODE EXAMPLE
#define KEY_ESC	53
#define KEY_Q	12
#define KEY_W	13
#define KEY_E	14
#define KEY_R	15
#define KEY_A	0
#define KEY_S	1
#define KEY_D	2

// Since the function key_press() can receive only one argument,
// all the argument should be gathered in one strucuture.
// x, y and str are not used in this program.
typedef struct	s_param
{
	int		x;
	int		y;
	char	str[3];
}				t_param;

// Only param-x will be used in this program.
void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int		key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W) // when the key 'w' is pressed
		param->x++;
	else if (keycode == KEY_S) // when the key 's' is pressed
		param->x--;
	else if (keycode == KEY_ESC) // when the key 'esc' is pressed, it turns off the program
		exit(0);
	printf("x : %d\n", param->x);
	return (0);
}


int		main(void)
{
	void	*mlx;
	void	*win;
	t_param	param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	printf("===================================\n");
	printf("'W'\t\t: add 1 to x\n");
	printf("'S'\t\t: Subtract 1 from x\n");
	printf("'ESC'\t\t: Exit the program.\n");
	printf("'Other keys'\t: print current x\n");
	printf("===================================\n");

	printf("Current x = 3\n");
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx);
}
