/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:58:01 by engo              #+#    #+#             */
/*   Updated: 2022/10/27 19:26:39 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_exit(t_all *all)
{
	int		y;
	int		x;

	y = all->data.player_y;
	x = all->data.player_x;
	if (all->data.up == 1)
	{
		if (all->map[y - 1][x] == 'E' && all->data.collectibles > 0)
			return (0);
		else if (all->map[y - 1][x] == 'E' && all->data.collectibles == 0)
			all->win = 1;
	}
	if (all->data.left == 1)
	{
		if (all->map[y][x - 1] == 'E' && all->data.collectibles > 0)
			return (0);
		else if (all->map[y][x - 1] == 'E' && all->data.collectibles == 0)
			all->win = 1;
	}
	if (can_exit2(all, y, x) == 0)
		return (0);
	return (1);
}

void	collect_all(t_all *all)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	j = -1;
	c = 0;
	while (all->map[++i])
	{
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'C')
				c++;
		}
		j = 0;
	}
	all->data.collectibles = c;
}

int	can_move2(t_all *all, int y, int x)
{
	if (all->data.right == 1)
	{
		if (all->map[y][x + 1] == '1')
			return (0);
	}
	return (1);
}

int	can_move(t_all *all)
{
	int		y;
	int		x;

	y = all->data.player_y;
	x = all->data.player_x;
	if (all->data.up == 1)
	{
		if (all->map[y - 1][x] == '1')
			return (0);
	}
	if (all->data.left == 1)
	{
		if (all->map[y][x - 1] == '1')
			return (0);
	}
	if (all->data.down == 1)
	{
		if (all->map[y + 1][x] == '1')
			return (0);
	}
	if (can_move2(all, y, x) == 0)
		return (0);
	return (1);
}

void	get_pos_player(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (all->map[++i])
	{
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'P')
			{
				all->data.player_y = i;
				all->data.player_x = j;
				return ;
			}
		}
		j = 0;
	}
}
