/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:52 by engo              #+#    #+#             */
/*   Updated: 2022/11/15 18:31:13 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_map(int keysym, t_all *g)
{
	if (keysym == 65307)
		mlx_loop_end(g->data.mlx_ptr);
	return (0);
}

int	close_win(t_all *d)
{
	mlx_loop_end(d->data.mlx_ptr);
	return (0);
}

static void	begin_parse_error(t_all *jeu)
{
	get_pos_player(jeu);
	if (jeu->player > 1 || jeu->player == 0)
		ft_putstr_fd("Error, invalid number of player.\n", 2);
	if (jeu->exit > 1 || jeu->exit == 0)
		ft_putstr_fd("Error, invalid number of exit.\n", 2);
	if (jeu->exit > 1 || jeu->exit == 0 || jeu->player > 1 || jeu->player == 0)
	{
		free_map(jeu->map);
		mlx_destroy_display(jeu->data.mlx_ptr);
		free(jeu->data.mlx_ptr);
		exit (1);
	}
}

void	size_window_limit(t_all *all)
{
	if (all->x * 50 > 1920 || all->y * 50 > 1080)
	{
		ft_putstr_fd("The window of the game is too big.\n", 2);
		mlx_destroy_display(all->data.mlx_ptr);
		free(all->data.mlx_ptr);
		free_map(all->map);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_all	jeu;

	if (check_args(ac, av) == 1)
		exit (1);
	if (ac == 2)
	{
		init_struct(&jeu);
		jeu.data.mlx_ptr = mlx_init();
		open_map(&jeu, av);
		init_size_map(&jeu);
		size_window_limit(&jeu);
		begin_parse_error(&jeu);
		ft_check_assets(&jeu);
		struct_path(jeu.map, &jeu);
		jeu.data.mlx_win = mlx_new_window(jeu.data.mlx_ptr, jeu.x * 50,
				jeu.y * 50, NAME);
		init_img(&jeu);
		mlx_key_hook(jeu.data.mlx_win, keybinds, &jeu);
		mlx_loop_hook(jeu.data.mlx_ptr, all_map, &jeu);
		mlx_hook(jeu.data.mlx_win, 33, 1L << 17, &close_win, &jeu);
		mlx_hook(jeu.data.mlx_win, 2, 1L << 0, &close_map, &jeu);
		mlx_loop(jeu.data.mlx_ptr);
	}
	free_img(&jeu);
	return (0);
}
