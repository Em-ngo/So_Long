/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:36:31 by engo              #+#    #+#             */
/*   Updated: 2022/11/12 23:08:45 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_r(t_all *all)
{
	all->data.right = 1;
	if (can_move(all) && can_exit(all))
	{
		all->map[all->data.player_y][all->data.player_x] = '0';
		all->data.player_x++;
		all->map[all->data.player_y][all->data.player_x] = 'P';
		all->moves++;
		printf("Cest votre %de pas\n", all->moves);
	}
	all->data.right = 0;
}

void	move_d(t_all *all)
{
	all->data.down = 1;
	if (can_move(all) && can_exit(all))
	{
		all->map[all->data.player_y][all->data.player_x] = '0';
		all->data.player_y++;
		all->map[all->data.player_y][all->data.player_x] = 'P';
		all->moves++;
		printf("Cest votre %de pas\n", all->moves);
	}
	all->data.down = 0;
}

void	move_l(t_all *all)
{
	all->data.left = 1;
	if (can_move(all) && can_exit(all))
	{
		all->map[all->data.player_y][all->data.player_x] = '0';
		all->data.player_x--;
		all->map[all->data.player_y][all->data.player_x] = 'P';
		all->moves++;
		printf("Cest votre %de pas\n", all->moves);
	}
	all->data.left = 0;
}


void	move_u(t_all *all)
{
	all->data.up = 1;
	if (can_move(all) && can_exit(all))
	{
		all->map[all->data.player_y][all->data.player_x] = '0';
		all->data.player_y--;
		all->map[all->data.player_y][all->data.player_x] = 'P';
		all->moves++;
		printf("Cest votre %de pas\n", all->moves);
	}
	all->data.up = 0;
}

int	keybinds(int keycode, t_all *all)
{
	if (keycode == 'w')
		move_u(all);
	if (keycode == 'a')
		move_l(all);
	if (keycode == 's')
		move_d(all);
	if (keycode == 'd')
		move_r(all);
	collect_all(all);
	return (0);
}
