/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:07:21 by engo              #+#    #+#             */
/*   Updated: 2022/11/18 14:59:55 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_all *g)
{
	free_map(g->map);
	mlx_destroy_image(g->data.mlx_ptr, g->image[0].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[1].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[2].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[3].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[4].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[5].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[6].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[7].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[8].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[9].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[10].img);
	mlx_destroy_window(g->data.mlx_ptr, g->data.mlx_win);
	mlx_destroy_display(g->data.mlx_ptr);
	free(g->data.mlx_ptr);
}
