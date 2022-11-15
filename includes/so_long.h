/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:14 by engo              #+#    #+#             */
/*   Updated: 2022/11/15 13:46:39 by vloth            ###   ########.fr       */
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
# include "ft_printf.h"

# define NAME "So_Long"
# define WALL "sprites/wall.xpm"
# define PLAYER "sprites/player.xpm"
# define COLLECT "sprites/collect.xpm"
# define FLOOR "sprites/floor.xpm"
# define EXIT "sprites/exit.xpm"

typedef struct s_gnl
{
	char	*save;
	char	*tmp;
}				t_gnl;

typedef struct s_path
{
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
	int		moves;
	int		player;
	int		exit;
	t_data	data;
	t_img	image[5];
}				t_all;

void	free_map(char **map);
void	free_img(t_all *g);
void	free_ptr(t_all *g);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);

void	open_map(t_all *g, char **av);
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
void	goodpath(char **map, t_path *p, t_all *all);
void	struct_path(char **map, t_all *g);
void	valid_path(char **copy, int x, int y);
int		format_checker(char *str);
char	**copy_map(char **map);
void	free_map(char **map);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s1);
int		check_args(int ac, char **av);
void	free_all(t_all *all, t_path *p, char **map);
void	free_pathfinding(t_all *all, t_path *p, char **map);
int		check_assets(char *path);
void	ft_check_assets(t_all *all);
void	free_free(t_all *all);
void	check_character(t_all *all);

#endif