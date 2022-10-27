/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/27 13:51:55 by engo             ###   ########.fr       */
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

# define NAME "So_Long"
# define WALL "sprites/wall.xpm"
# define PLAYER "sprites/player.xpm"
# define COLLECT "sprites/collect.xpm"
# define FLOOR "sprites/floor.xpm"
# define EXIT "sprites/exit.xpm"

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

typedef struct s_img
{
	void		*img;
	int			height;
	int			width;
	char		*adr;
	char		*path;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*mlx_ptr;
	void	*mlx_win;
	int		player_x;
	int		player_y;
	int		collectibles;
}				t_data;

typedef struct s_all
{
	int		ac;
	char	**av;
	char	**map;
	int		nb_lines;
	int		width;
	int		height;
	int		steps;
	int		fd;
	int		x;
	int		y;
	t_data	window;
	t_data	img;
	t_data	data;
	t_img	image[5];
}				t_all;

void	open_map(t_all *g, char **av);
void	free_ptr(t_all *g);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	**get_next_line(int fd);
void	init_size_map(t_all *g);
void	init_img(t_all *all);
void	put_img_on_window(t_all *all, int x_pos, int y_pos, char c);
int		all_map(t_all *all);
#endif