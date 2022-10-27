/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:36:31 by engo              #+#    #+#             */
/*   Updated: 2022/10/27 17:17:54 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_r(t_all *all, int moves)
{
	all->map[all->data.player_y][all->data.player_x] = '0';
	all->data.player_x++;
	all->map[all->data.player_y][all->data.player_x] = 'P';
	moves++;
}

void	move_d(t_all *all, int moves)
{
	all->map[all->data.player_y][all->data.player_x] = '0';
	all->data.player_y++;
	all->map[all->data.player_y][all->data.player_x] = 'P';
	moves++;
}

void	move_l(t_all *all, int moves)
{
	all->map[all->data.player_y][all->data.player_x] = '0';
	all->data.player_x--;
	all->map[all->data.player_y][all->data.player_x] = 'P';
	moves++;
}


void	move_u(t_all *all, int moves)
{
	printf("%d\n", all->data.player_x);
	printf("%d\n", all->data.player_y);
	all->map[all->data.player_y][all->data.player_x] = '0';
	all->data.player_y--;
	all->map[all->data.player_y][all->data.player_x] = 'P';
	moves++;
}

int	keybinds(int keycode, t_all *all)
{
	static int	moves;
	int			i;

	i = 0;
	moves = 0;
	if (keycode == 'w')
		move_u(all, moves);
	if (keycode == 'a')
		move_l(all, moves);
	if (keycode == 's')
		move_d(all, moves);
	if (keycode == 'd')
		move_r(all, moves);
	while (all->map[i])
		printf("%s\n", all->map[i++]);
	// ft_putnbr_fd(moves, 1);
	// ft_putstr_fd("\n", 1);
	return (0);
}
