/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:57 by engo              #+#    #+#             */
/*   Updated: 2022/11/15 12:08:29 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pathfinding(t_all *all, t_path *p, char **map)
{
	ft_putstr_fd("Non valid path\n", 2);
	mlx_destroy_display(all->data.mlx_ptr);
	free_all(all, p, map);
	exit (1);
}

void	free_free(t_all *g)
{
	free_map(g->map);
	mlx_destroy_display(g->data.mlx_ptr);
	free(g->data.mlx_ptr);
}

void	free_all(t_all *all, t_path *p, char **map)
{
	free(all->data.mlx_ptr);
	free_map(map);
	free_map(all->map);
	free(p);
}

void	free_img(t_all *g)
{
	int	i;

	i = 0;
	if (g->map != NULL)
	{
		while (g->map[i] != NULL)
		{
			free(g->map[i]);
			i++;
		}
		free(g->map);
	}
	mlx_destroy_image(g->data.mlx_ptr, g->image[0].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[1].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[2].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[3].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[4].img);
	mlx_destroy_window(g->data.mlx_ptr, g->data.mlx_win);
	mlx_destroy_display(g->data.mlx_ptr);
	free(g->data.mlx_ptr);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}
