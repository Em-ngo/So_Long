#include "../includes/so_long.h"

void	init_struct(t_error *error, t_all *jeu)
{
	error->closed = 0;
	error->square = 0;
	error->size = 0;
	error->player = 0;
	error->collectible = 0;
	error->exit = 0;
	error->fullmap = 0;
	jeu->row = 0;
	jeu->column = 0;
	jeu->move = 0;
}
