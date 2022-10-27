/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:52 by engo              #+#    #+#             */
/*   Updated: 2022/10/24 18:43:54 by engo             ###   ########.fr       */
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

	jeu.data.mlx_ptr = mlx_init();
	open_map(&jeu, av);
	init_size_map(&jeu);
	jeu.data.mlx_win = mlx_new_window(jeu.data.mlx_ptr, jeu.width * 50, jeu.height * 50, NAME);
	// init_img(&jeu);
	// jeu.g->wall.ptr = mlx_new_image(jeu.mlx_ptr, jeu.width, jeu.height);
	// put_img(jeu.mlx_ptr, jeu.window);
	mlx_hook(jeu.data.win_ptr, 33, 1L << 17, &close_map, &jeu);
	mlx_loop(jeu.data.mlx_ptr);
	// free_ptr(&jeu);
}
