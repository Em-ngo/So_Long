/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:52 by engo              #+#    #+#             */
/*   Updated: 2022/11/10 15:38:41 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	close_map(int keysym, t_all *g)
{
	if (keysym == 65307)
		mlx_loop_end(g->data.mlx_ptr);
	return (0);
}

int	close_win(t_all *d)
{
	mlx_loop_end(d->data.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	jeu;
	(void)ac;

	init_struct(&jeu);
	jeu.data.mlx_ptr = mlx_init();
	open_map(&jeu, av);
	get_pos_player(&jeu);
	init_size_map(&jeu);
	struct_path(jeu.map, &jeu);
	jeu.data.mlx_win = mlx_new_window(jeu.data.mlx_ptr, jeu.x * 50, jeu.y * 50,
			NAME);
	init_img(&jeu);
	mlx_key_hook(jeu.data.mlx_win, keybinds, &jeu);
	mlx_loop_hook(jeu.data.mlx_ptr, all_map, &jeu);
	mlx_hook(jeu.data.mlx_win, 33, 1L << 17, &close_win, &jeu);
	mlx_hook(jeu.data.mlx_win, 2, 1L << 0, &close_map, &jeu);
	mlx_loop(jeu.data.mlx_ptr);
	hakai_img(&jeu);
}
