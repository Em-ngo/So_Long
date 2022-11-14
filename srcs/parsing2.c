/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:00:31 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 18:03:35 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_assets(t_all *all)
{
	if (check_assets(PLAYER) == 1 || check_assets(WALL) == 1
		|| check_assets(COLLECT) == 1 || check_assets(FLOOR) == 1
		|| check_assets(EXIT) == 1)
	{
		ft_putstr_fd("Error, no texture loaded.\n", 2);
		free_map(all->map);
		mlx_destroy_display(all->data.mlx_ptr);
		free(all->data.mlx_ptr);
		exit (1);
	}
}

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
	ft_putstr_fd("Format of the map non valid.\n", 2);
	return (0);
}

int	check_assets(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	else
		close(fd);
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error, a map is needed.\n", 2);
		exit (1);
	}
	else if (ac > 2)
	{
		ft_putstr_fd("Error, too many arguments.\n", 2);
		exit (1);
	}
	else
	{
		if (format_checker(av[1]) == 0)
			exit (1);
	}
	return (0);
}
