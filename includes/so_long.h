/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/19 14:52:16 by engo             ###   ########.fr       */
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

typedef struct s_pos
{
	int	x;
	int	y;
	int	right;
	int	left;
}				t_pos;

typedef struct s_all
{
	void	*mlx_ptr;
	void	*window;
	int		width;
	int		height;
	void	*img;
	char	*name;
	char	**map;
	int		row;
	int		column;
	int		x;
	int		y;
	int		move;
}				t_all;

void	free_ptr(t_all *g);
int		close_map(t_all *g);

#endif