/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/24 18:45:32 by engo             ###   ########.fr       */
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
# include <stddef.h>
# include <sys/types.h>
# include <unistd.h>


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


typedef struct s_image
{
	void		*ptr;
	int			height;
	int			width;
}				t_image;

typedef struct s_simg
{
	t_image		w;
	t_image		p;
	t_image		c;
	t_image		e;
	t_image		f;
}				t_simg;


typedef struct s_all
{
	void	*mlx_ptr;
	void	*window;
	char	*name;
	char	**map;
	// int		*img;
	int		x;
	int		y;
	t_simg	g;
}				t_all;

void	*put_img(void *mlx, void *window);
t_image	ft_new_sprite(void *mlx, char *path);
void	open_map(t_all *g, char **av);
void	free_ptr(t_all *g);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	**get_next_line(int fd);
void	init_size_map(t_all *g);
void	init_img(t_all *all);

#endif