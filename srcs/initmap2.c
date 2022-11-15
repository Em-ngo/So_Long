/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:01:33 by engo              #+#    #+#             */
/*   Updated: 2022/11/15 13:54:48 by vloth            ###   ########.fr       */
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
	int i;
	int n;

	i = -1;
	n = -1;
	while (all->map[++i])
	{
		while(all->map[i][++n])
		{
			if(all->map[i][n] != '0' && all->map[i][n] != 'E' && all->map[i][n] != 'P' &&
				all->map[i][n] != '1' && all->map[i][n] != 'C')
			{
				ft_putstr_fd("Error, no valid map\n", 2);
				free_free(all);
				exit (1);
			}
		}
		n = -1;
	}
}