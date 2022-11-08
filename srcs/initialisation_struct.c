#include "../includes/so_long.h"

void	init_struct(t_all *all, t_path *path)
{

	all->data.right = 0;
	all->data.down = 0;
	all->data.left = 0;
	all->data.up = 0;
	all->data.collectibles = 0;
	all->win = 0;
	path->exit_x = 0;
	path->exit_y = 0;
}
