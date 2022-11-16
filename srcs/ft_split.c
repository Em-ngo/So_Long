/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:13:21 by engo              #+#    #+#             */
/*   Updated: 2022/11/16 12:48:19 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

size_t	ft_word(char const *str, char c)
{
	size_t	word;
	size_t	state;

	state = 1;
	word = 0;
	while (*str)
	{
		if (*str == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		str++;
	}
	return (word);
}

size_t	word_lenght(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**dest;

	i = 0;
	if (s == 0)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!dest)
		return (NULL);
	while (ft_word(s, c))
	{
		while (*s && *s == c)
			s++;
		dest[i] = (char *)malloc(sizeof(char) * (word_lenght(s, c) + 1));
		if (!dest[i])
			return (ft_free(dest));
		j = 0;
		while (*s != c && *s)
			dest[i][j++] = *s++;
		dest[i][j] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	check_double_n(char *line, t_all *all, t_gnl *g)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_putstr_fd("Error map.\n", 2);
			free(g->tmp);
			free(line);
			mlx_destroy_display(all->data.mlx_ptr);
			free(all->data.mlx_ptr);
			exit (9);
			return (1);
		}
	}
	return (0);
}
