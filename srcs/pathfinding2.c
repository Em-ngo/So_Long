#include "so_long.h"

void	pos_exit(s_path *path)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (path->map_tmp[i++])
	{
		while (path->map_tmp[i][n++])
		{
			if (path->map_tmp[i][n] == 'E')
			{
				path->exit_x = n;
				path->exit_y = i;
				return ;
			}
		}
		n = 0;
	}
}

char	**copy_map(char **map)
{
	int		x;
	char	**copy;

	x = 0;
	while (map[x])
		++x;
	++x;
	copy = malloc(x * sizeof(char *));
	x = 0;
	while (map[x])
	{
		copy[x] = ft_strdup(map[x]);
		printf("%s", copy[x]);
		++x;
	}
	copy[x] = NULL;
	return (copy);
}

void	valid_path(char **copy, int x, int y)
{
	copy[x][y] = 'P';
	if (copy[x + 1][y] == 'C' || copy[x + 1][y] == '0' || copy[x + 1][y] == 'E')
		valid_path(copy, x + 1, y);
	if (copy[x - 1][y] == 'C' || copy[x - 1][y] == '0' || copy[x - 1][y] == 'E')
		valid_path(copy, x - 1, y);
	if (copy[x][y + 1] == 'C' || copy[x][y + 1] == '0' || copy[x][y + 1] == 'E')
		valid_path(copy, x, y + 1);
	if (copy[x][y - 1] == 'C' || copy[x][y - 1] == '0' || copy[x][y - 1] == 'E')
		valid_path(copy, x, y - 1);
}

void	goodpath(char **map)
{
	int	y;
	int	x;
	t_path	path;

	y = -1;
	x = -1;
	if (map[path.exit_y + 1][path.exit_x] != 'P' &&
			map[path.exit_y - 1][path.exit_x] != 'P' &&
			map[path.exit_y][path.exit_x + 1] != 'P' &&
			map[path.exit_y][path.exit_x - 1] != 'P')
	{
		ft_putstr_fd("Non valid path\n", 1);
		exit (1);
	}
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				ft_putstr_fd("Non valid path\n", 1);
				exit (1);
			}
		}
		x = 0;
	}
}

void	struct_path(char **map)
{
	t_path	path;
    t_data	data;
    char	**copy;
    int     i;

	copy = copy_map(map);
	path.player_x = data.player_x;
	path.player_y = data.player_y;
	pos_exit(&path);
	valid_path(copy, path.player_x, path.player_y);
	i = 0;
	while (copy[i])
		printf("%s\n", copy[i++]);
	goodpath(map);
}
