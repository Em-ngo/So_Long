/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_and_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/9/24 16:37:00 by engo              #+#    #+#             */
/*   Updated: 2022/11/16 17:36:48 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_on_window_2(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '0')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[2].img, x_pos, y_pos);
	else if (c == 'E')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[3].img, x_pos, y_pos);
}

void	put_img_on_window(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[0].img, x_pos, y_pos);
	else if (c == 'P')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[1].img, x_pos, y_pos);
	else if (c == 'C')
		init_anim(all, x_pos, y_pos);
	else
		put_img_on_window_2(all, x_pos, y_pos, c);
}

void	init_img(t_all *all)
{
	all->image[0].img = mlx_xpm_file_to_image(all->data.mlx_ptr, WALL,
			&all->image[0].height, &all->image[0].width);
	all->image[1].img = mlx_xpm_file_to_image(all->data.mlx_ptr, PLAYER,
			&all->image[1].height, &all->image[1].width);
	all->image[2].img = mlx_xpm_file_to_image(all->data.mlx_ptr, FLOOR,
			&all->image[2].height, &all->image[2].width);
	all->image[3].img = mlx_xpm_file_to_image(all->data.mlx_ptr, EXIT,
			&all->image[3].height, &all->image[3].width);
	all->image[4].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT1,
			&all->image[4].height, &all->image[4].width);
	all->image[5].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT2,
			&all->image[5].height, &all->image[5].width);
	all->image[6].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT3,
			&all->image[6].height, &all->image[6].width);
	all->image[7].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT4,
			&all->image[7].height, &all->image[7].width);
	all->image[8].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT5,
			&all->image[8].height, &all->image[8].width);
	all->image[9].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT6,
			&all->image[9].height, &all->image[9].width);
	all->image[10].img = mlx_xpm_file_to_image(all->data.mlx_ptr, CAT7,
			&all->image[10].height, &all->image[10].width);
}

void	open_map(t_all *g, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map not found.\n", 2);
		mlx_destroy_display(g->data.mlx_ptr);
		free(g->data.mlx_ptr);
		exit (1);
	}
	g->map = get_next_line(fd, g);
	if (g->map == NULL)
	{	
		ft_putstr_fd("Error, this is a not file.\n", 2);
		free_free(g);
		exit (1);
	}
	close(fd);
	check_character(g);
}

void	init_size_map(t_all *g)
{
	int	i;

	i = 0;
	g->x = ft_strlen(g->map[i]);
	while (g->map[i])
	{	
		if (ft_strlen(g->map[0]) != ft_strlen(g->map[i]))
		{
			ft_putstr_fd("Error, the map is not rectangular.\n", 2);
			free_free(g);
			exit (1);
		}
		i++;
	}
	g->y = i;
	collect_all(g);
	if (g->data.collectibles == 0)
	{
		ft_putstr_fd("No collectibles found.\n", 2);
		free_free(g);
		exit (1);
	}
}
