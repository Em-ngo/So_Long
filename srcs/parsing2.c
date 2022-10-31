/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:00:31 by engo              #+#    #+#             */
/*   Updated: 2022/10/31 17:30:15 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_exit2(t_all *all, int y, int x)
{
	if (all->data.down == 1)
	{
		if (all->map[y + 1][x] == 'E' && all->data.collectibles > 0)
			return (0);
		else if (all->map[y + 1][x] == 'E' && all->data.collectibles == 0)
			all->win = 1;
	}
	if (all->data.right == 1)
	{
		if (all->map[y][x + 1] == 'E' && all->data.collectibles > 0)
			return (0);
		else if (all->map[y][x + 1] == 'E' && all->data.collectibles == 0)
			all->win = 1;
	}
	return (1);
}

int	format_checker(char *str)
{	
	if (!ft_strncmp(ft_strrchr(str, '.'), ".ber", 5))
		return (1);
	ft_putstr_fd("Format of the map non valid", 1);
	return (0);
}

