/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:58:38 by engo              #+#    #+#             */
/*   Updated: 2022/10/24 18:32:15 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

// void	*put_img(void *mlx, void *window)
// {
// 	t_image	image;
// 	int		x_pos;
// 	int		y_pos;

// 	x_pos = 450;
// 	y_pos = 450;
// 	image = ft_new_sprite(mlx, "./sprites/player.xpm");
// 	mlx_put_image_to_window(mlx, window, image.ptr, x_pos, y_pos);
// 	return (image.ptr);
// }


// t_image	ft_new_sprite(void *mlx, char *path)
// {
// 	t_image	img;

// 	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
// 	img.pixels = mlx_get_data_addr(img.ptr, &img.bits, &img.line, &img.endian);
// 	return (img);
// }
