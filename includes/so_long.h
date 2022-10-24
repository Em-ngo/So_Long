/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/23 17:36:22 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdlib.h>


typedef struct s_error
{
	int		player;
	int		collectible;
	int		exit;
	int		fullmap;
	int		shape;
	int		closed;
	size_t	size;
}				t_error;

typedef struct s_vector
{
	int	x;
	int	y;
}			t_vector;

typedef struct s_image
{
	void		*ptr;
	char		*pixels;
	int			bits;
	int			line;
	int			endian;
	t_vector	size;
}				t_image;


typedef struct s_all
{
	void	*mlx_ptr;
	void	*window;
	void	*img;
	char	*name;
	char	**map;
	int		width;
	int		height;
	int		row;
	int		column;
	int		x;
	int		y;
	int		move;
}				t_all;

void	*put_img(void *mlx, void *window);
t_image	ft_new_sprite(void *mlx, char *path);

void	free_ptr(t_all *g);

#endif