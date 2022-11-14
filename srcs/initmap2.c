/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:01:33 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 10:30:33 by engo             ###   ########.fr       */
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
		ft_printf("Won in %d moves\n", all->moves);
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
