/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:01:33 by engo              #+#    #+#             */
/*   Updated: 2022/11/16 18:16:54 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_map(t_all *all)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	y = 0;
	if (all->win == 1)
	{
		mlx_loop_end(all->data.mlx_ptr);
		ft_printf("Won in %d moves.\n", all->moves);
	}
	while (all->map[++i])
	{
		x = 0;
		j = -1;
		while (all->map[i][++j])
		{
			put_img_on_window(all, x, y, all->map[i][j]);
			x += 50;
		}
		y += 50;
	}
	return (0);
}

void	check_character(t_all *all)
{
	int		i;
	int		n;

	i = -1;
	n = -1;
	while (all->map[++i])
	{
		while (all->map[i][++n])
		{
			if (all->map[i][n] != '0' && all->map[i][n] != 'E'
				&& all->map[i][n] != 'P' && all->map[i][n] != '1'
				&& all->map[i][n] != 'C')
			{
				ft_putstr_fd("Error, the map is not valid.\n", 2);
				free_free(all);
				exit (1);
			}
		}
		n = -1;
	}
}

void	init_anim2(t_all *a, int x, int y, int *i)
{
	if (*i >= 2000 && *i < 2400)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[9].img, x, y);
	else if (*i == 2400)
	{
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[10].img, x, y);
		*i = 1;
	}
}

void	init_anim(t_all *a, int x, int y)
{
	static int	i = 1;

	i++;
	if (i < 400)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[4].img, x, y);
	else if (i >= 400 && i < 800)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[5].img, x, y);
	else if (i >= 800 && i < 1200)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[6].img, x, y);
	else if (i >= 1200 && i < 1600)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[7].img, x, y);
	else if (i >= 1600 && i < 2000)
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.mlx_win,
			a->image[8].img, x, y);
	else
		init_anim2(a, x, y, &i);
}
