/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:09:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/31 19:57:40 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_exit(t_path *path)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (path->map_tmp[i++])
	{
		while (path->map_tmp[i][n++])
		{
			if (path->map_tmp[i][n] == 'E')
			{
				path->exit_x = n;
				path->exit_y = i;
				return ;
			}
		}
		n = 0;
	}
}


char**	testThib(char **map)
{
	int i = 0;
	char **tmp = NULL;

	while (map[i])
		i++;
	tmp = malloc(sizeof(tmp) * (i + 1));
	tmp[i] = 0;
	i = 0;
	// if (map == tmp)
		// printf(_RED "pas bon\n"_NC);
	// printf("map = %p\n", &map);
	// printf("tmp = %p\n", &tmp);
	while (map[i]) {
		tmp[i] = ft_strdup((map[i]));
		// if (map[i] == tmp[i])
			// printf(_RED "pas bon\n"_NC);
		// printf("map = %p\n", &map[i]);
		// printf("tmp = %p\n", &tmp[i]);
		i++;
	}

	return (tmp);
}

void	struct_path(t_all *data)
{
	t_path	path;
	(void)path;

	// path.map_tmp = *&(data->map);
	path.map_tmp = testThib(data->map);
	path.player_x = data->data.player_x;
	path.player_y = data->data.player_y;
	// pos_exit(&path);
	// valid_path(&path, path.player_x, path.player_y);
	//i = 0;
	//while (path->map_tmp[i])
	//	printf("%s\n", path->map_tmp[i++]);
	// goodpath(&path);
}

void	valid_path(t_path *path, int x, int y)
{
	path->map_tmp[y][x] = 'P';
	if (path->map_tmp[y][x + 1] == 'C' || path->map_tmp[y][x + 1] == '0')
		valid_path(path, x + 1, y);
	if (path->map_tmp[y][x - 1] == 'C' || path->map_tmp[y][x - 1] == '0')
		valid_path(path, x - 1, y);
	if (path->map_tmp[y + 1][x] == 'C' || path->map_tmp[y + 1][x] == '0')
		valid_path(path, x, y + 1);
	if (path->map_tmp[y - 1][x] == 'C' || path->map_tmp[y - 1][x] == '0')
		valid_path(path, x, y - 1);
	return ;
}

void	goodpath(t_path *path)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (path->map_tmp[path->exit_y + 1][path->exit_x] != 'P' &&
			path->map_tmp[path->exit_y - 1][path->exit_x] != 'P' &&
			path->map_tmp[path->exit_y][path->exit_x + 1] != 'P' &&
			path->map_tmp[path->exit_y][path->exit_x - 1] != 'P')
	{
		ft_putstr_fd("Non valid path\n", 1);
		exit (1);
	}
	while (path->map_tmp[++y])
	{
		while (path->map_tmp[y][++x])
		{
			if (path->map_tmp[y][x] == 'C')
			{
				ft_putstr_fd("Non valid path\n", 1);
				exit (1);
			}
		}
		x = 0;
	}
}

