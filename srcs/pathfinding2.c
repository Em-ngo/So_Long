/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:25 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 10:19:20 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_exit(char **map, t_path *p)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (map[i])
	{
		while (map[i][n])
		{
			if (map[i][n] == 'E')
			{
				p->exit_x = n;
				p->exit_y = i;
				return ;
			}
			n++;
		}
		i++;
		n = 0;
	}
}

char	**copy_map(char **map)
{
	int		x;
	char	**copy;

	x = 0;
	while (map[x])
		++x;
	++x;
	copy = malloc(x * sizeof(char *));
	x = 0;
	while (map[x])
	{
		copy[x] = ft_strdup(map[x]);
		++x;
	}
	copy[x] = NULL;
	return (copy);
}

void	valid_path(char **copy, int x, int y)
{
	copy[x][y] = 'P';
	if (copy[x + 1][y] == 'C' || copy[x + 1][y] == '0')
		valid_path(copy, x + 1, y);
	if (copy[x - 1][y] == 'C' || copy[x - 1][y] == '0')
		valid_path(copy, x - 1, y);
	if (copy[x][y + 1] == 'C' || copy[x][y + 1] == '0')
		valid_path(copy, x, y + 1);
	if (copy[x][y - 1] == 'C' || copy[x][y - 1] == '0')
		valid_path(copy, x, y - 1);
	return ;
}

void	goodpath(char **map, t_path *p)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (map[p->exit_y + 1][p->exit_x] != 'P' &&
			map[p->exit_y - 1][p->exit_x] != 'P' &&
			map[p->exit_y][p->exit_x + 1] != 'P' &&
			map[p->exit_y][p->exit_x - 1] != 'P')
	{
		ft_putstr_fd("Non valid path\n", 1);
		exit (1);
	}
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				ft_putstr_fd("Non valid path\n", 1);
				exit (1);
			}
		}
		x = -1;
	}
}

void	struct_path(char **map, t_all *g)
{
	t_path	*path;
	char	**copy;

	path = malloc(sizeof(*path));
	copy = copy_map(map);
	path->player_x = g->data.player_x;
	path->player_y = g->data.player_y;
	pos_exit(map, path);
	valid_path(copy, path->player_y, path->player_x);
	goodpath(copy, path);
	free(path);
	free_map(copy);
}
