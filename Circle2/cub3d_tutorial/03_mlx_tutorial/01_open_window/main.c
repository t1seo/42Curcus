#include "../include/mlx.h"

int		main(void)
{
	void	*mlx; // screen connection identifier
	void	*win; // window identifier

	mlx = mlx_init();
	// paramter: screen connection identifier, window size, window title
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);
}
