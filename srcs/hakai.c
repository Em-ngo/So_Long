/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hakai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:57 by vloth             #+#    #+#             */
/*   Updated: 2022/11/10 16:27:45 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	hakai_img(t_all *g)
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

void	freedom(char **map)
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