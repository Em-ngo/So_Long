/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:00 by engo              #+#    #+#             */
/*   Updated: 2022/10/25 19:00:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	put_img_on_window2(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '0')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->window, &all->g.f,
			x_pos, y_pos);
		printf("sol\n");
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->window, &all->g.e,
			x_pos, y_pos);
		printf("exit\n");
	}
}

void	put_img_on_window(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->window, &all->g.w,
			x_pos, y_pos);
		printf("wall\n");
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->window, &all->g.p,
			x_pos, y_pos);
		printf("player\n");
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->window, &all->g.c,
			x_pos, y_pos);
		printf("collectibles\n");
	}
	else
		put_img_on_window2(all, x_pos, y_pos, c);
}

// mlx_put_image_to_window(all->mlx_ptr, all->window, x_pos, y_pos);

void	init_img(t_all *all)
{
	all->g.w.ptr = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/wall.xpm",
			&all->g.w.height, &all->g.w.width);
	all->g.p.ptr = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/player.xpm",
			&all->g.p.height, &all->g.p.width);
	all->g.e.ptr = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/exit.xpm",
			&all->g.e.height, &all->g.e.width);
	all->g.c.ptr = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/collect.xpm",
			&all->g.c.height, &all->g.c.width);
	all->g.f.ptr = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/sol.xpm",
			&all->g.f.height, &all->g.f.width);
}

void	open_map(t_all *g, char **av)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	g->map = get_next_line(fd);
	while (g->map[i])
		printf("%s\n", g->map[i++]);
}

void	init_size_map(t_all *g)
{
	int	i;

	i = 0;
	g->x = ft_strlen(g->map[i]);
	while (g->map[i])
		i++;
	g->y = i;
}
