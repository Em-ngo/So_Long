/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/10/31 19:00:32 by engo             ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

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
}				t_error;

typedef struct s_path
{
	char	**map_tmp;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_path;

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
	int		right;
	int		left;
	int		down;
	int		up;
}				t_data;

typedef struct s_all
{
	int		ac;
	char	**av;
	char	**map;
	int		nb_lines;
	int		steps;
	int		fd;
	int		x;
	int		y;
	int		win;
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
void	get_pos_player(t_all *all);
int		keybinds(int keycode, t_all *all);
int		can_move(t_all *all);
void	init_struct(t_all *all);
void	collect_all(t_all *all);
int		can_exit2(t_all *all, int y, int x);
int		can_exit(t_all *all);
void	ft_putstr_fd(char *s, int fd);
void	goodpath(t_path *path);
void	struct_path(t_all *data);
void	valid_path(t_path *path, int x, int y);
int		format_checker(char *str);
void	free_map(char **map);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s1);

#endif