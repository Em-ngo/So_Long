/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:09:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/31 18:55:43 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_exit(t_path *path, char **tmp)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (tmp[i++])
	{
		while (tmp[i][n++])
		{
			if (tmp[i][n] == 'E')
			{
				path->exit_x = n;
				path->exit_y = i;
				return ;
			}
		}
		n = 0;
	}
}

void	struct_path(t_all *data, char **map_tmp)
{
	t_path	path;
	int		i;
	char	**tmp;

	i = -1;
	tmp = malloc(sizeof(char *) * (data->y + 1));
	if (!tmp)
		return ;
	while (++i < data->y)
		tmp[i] = ft_strdup(map_tmp[i]);
	tmp[i] = NULL;
	path.player_x = data->data.player_x;
	path.player_y = data->data.player_y;
	pos_exit(&path, tmp);
	valid_path(tmp, path.player_x, path.player_y);
	//i = 0;
	//while (tmp[i])
	//	printf("%s\n", tmp[i++]);
	goodpath(&path, tmp);
}

void	valid_path(char **tmp, int x, int y)
{
	tmp[y][x] = 'P';
	if (tmp[y][x + 1] == 'C' || tmp[y][x + 1] == '0')
		valid_path(tmp, x + 1, y);
	if (tmp[y][x - 1] == 'C' || tmp[y][x - 1] == '0')
		valid_path(tmp, x - 1, y);
	if (tmp[y + 1][x] == 'C' || tmp[y + 1][x] == '0')
		valid_path(tmp, x, y + 1);
	if (tmp[y - 1][x] == 'C' || tmp[y - 1][x] == '0')
		valid_path(tmp, x, y - 1);
	return ;
}

void	goodpath(t_path *path, char **tmp)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (tmp[path->exit_y + 1][path->exit_x] != 'P' &&
			tmp[path->exit_y - 1][path->exit_x] != 'P' &&
			tmp[path->exit_y][path->exit_x + 1] != 'P' &&
			tmp[path->exit_y][path->exit_x - 1] != 'P')
	{
		ft_putstr_fd("Non valid path\n", 1);
		exit (1);
	}
	while (tmp[++y])
	{
		while (tmp[y][++x])
		{
			if (tmp[y][x] == 'C')
			{
				ft_putstr_fd("Non valid path\n", 1);
				exit (1);
			}
		}
		x = 0;
	}
}

