/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:58:01 by engo              #+#    #+#             */
/*   Updated: 2022/10/27 16:03:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
