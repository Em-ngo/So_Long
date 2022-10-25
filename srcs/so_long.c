/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:52 by engo              #+#    #+#             */
/*   Updated: 2022/10/25 19:02:53 by engo             ###   ########.fr       */
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
	if (g->mlx_ptr)
	{
		if (g->window)
		{
			// if (g->img)
				// free_image(g);
			mlx_destroy_window(g->mlx_ptr, g->window);
		}
		mlx_destroy_display(g->mlx_ptr);
		free(g->mlx_ptr);
		g->mlx_ptr = NULL;
	}
}

int	main(int ac, char **av)
{
	t_all	jeu;
	(void)ac;

	jeu.name = "So_Long";
	jeu.mlx_ptr = mlx_init();
	open_map(&jeu, av);
	init_size_map(&jeu);
	jeu.window = mlx_new_window(jeu.mlx_ptr, jeu.x * 50, jeu.y * 50, jeu.name);
	init_img(&jeu);
	all_map(&jeu);
	// jeu.g->wall.ptr = mlx_new_image(jeu.mlx_ptr, jeu.width, jeu.height);
	// put_img(jeu.mlx_ptr, jeu.window);
	mlx_hook(jeu.window, 33, 1L << 17, &close_map, &jeu);
	mlx_loop(jeu.mlx_ptr);
	// free_ptr(&jeu);
}
