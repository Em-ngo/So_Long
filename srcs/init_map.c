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

void	put_img_on_window_2(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '0')
	{
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->image[3].img,
			x_pos, y_pos);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->image[4].img,
			x_pos, y_pos);
	}
}

void	put_img_on_window(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->image[0].img,
			x_pos, y_pos);
		printf("wall\n");
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->image[1].img,
			x_pos, y_pos);
		printf("player\n");
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->image[2].img,
			x_pos, y_pos);
		printf("collectibles\n");
	}
	else
		put_img_on_window_2(all, x_pos, y_pos, c);
}


void	init_img(t_all *all)
{
	all->image[0].img = mlx_xpm_file_to_image(all->data.mlx_ptr, WALL,
			&all->image[0].height, &all->image[0].width);
	all->image[1].img = mlx_xpm_file_to_image(all->data.mlx_ptr, PLAYER,
			&all->image[1].height, &all->image[1].width);
	all->image[2].img = mlx_xpm_file_to_image(all->data.mlx_ptr, COLLECT,
			&all->image[2].height, &all->image[2].width);
	all->image[3].img = mlx_xpm_file_to_image(all->data.mlx_ptr, FLOOR,
			&all->image[3].height, &all->image[3].width);
	all->image[4].img= mlx_xpm_file_to_image(all->data.mlx_ptr, EXIT,
			&all->image[4].height, &all->image[4].width);
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
