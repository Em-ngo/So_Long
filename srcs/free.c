/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:15:01 by engo              #+#    #+#             */
/*   Updated: 2022/10/19 14:38:04 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	free_image(t_all *g)
{
	mlx_destroy_image(g->window.mlx_ptr, g->window.img.img);
	g->window.img.img = NULL;
	g->window.img.adr = NULL;
}

void	free_ptr(t_global *g)
{
	if (g->window.mlx_ptr)
	{
		if (g->window.win_ptr)
		{
			if (g->window.img.img)
				free_image(g);
			mlx_destroy_window(g->window.mlx_ptr, g->window.win_ptr);
		}
		mlx_destroy_display(g->window.mlx_ptr);
		free(g->window.mlx_ptr);
		g->window.mlx_ptr = NULL;
	}
}