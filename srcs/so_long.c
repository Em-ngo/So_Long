/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:52 by engo              #+#    #+#             */
/*   Updated: 2022/10/31 18:55:04 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	close_map(t_all *g)
{
	free_ptr(g);
	exit(0);
}

// static void	free_image(t_all *g)
// {
	// mlx_destroy_image(g->mlx_ptr, g->img);
	// g->img = NULL;
	// g->window.img.adr = NULL;
// }

void	free_ptr(t_all *g)
{
	if (g->data.mlx_ptr)
	{
		if (g->data.mlx_win)
		{
			// if (g->img)
				// free_image(g);
			mlx_destroy_window(g->data.mlx_ptr, g->data.mlx_win);
		}
		mlx_destroy_display(g->data.mlx_ptr);
		free(g->data.mlx_ptr);
		g->data.mlx_ptr = NULL;
	}
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
	jeu.data.mlx_win = mlx_new_window(jeu.data.mlx_ptr, jeu.x * 50, jeu.y * 50,
			NAME);
	struct_path(&jeu, jeu.map);
	init_img(&jeu);
	// jeu.data.img = mlx_new_image(jeu.data.mlx_ptr, jeu.x, jeu.y);
	mlx_key_hook(jeu.data.mlx_win, keybinds, &jeu);
	mlx_loop_hook(jeu.data.mlx_ptr, all_map, &jeu);
	mlx_hook(jeu.data.mlx_win, 33, 1L << 17, &close_map, &jeu);
	mlx_loop(jeu.data.mlx_ptr);
	// free_ptr(&jeu);
}
