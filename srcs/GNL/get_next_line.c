/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:10:31 by engo              #+#    #+#             */
/*   Updated: 2022/11/16 12:47:31 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*ndest;
	char	*nsrc;
	size_t	i;

	ndest = (char *)dest;
	nsrc = (char *)src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (n > i)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;

	if (s2 != 0)
	{
		join = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!join)
			return (0);
		ft_memcpy(join, s1, ft_strlen(s1));
		ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		join[ft_strlen(s1) + ft_strlen(s2)] = 0;
		free(s1);
		s1 = NULL;
		return (join);
	}
	return (s1);
}

char	*freeee(char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (i - 1 == 0)
		return (NULL);
	str = malloc(len * sizeof(const char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**get_next_line(int fd, t_all *all)
{
	static t_gnl		g;
	char				buff[BUFFER_SIZE + 1];
	char				*line;
	char				**final;
	int					ret;

	ret = 1;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 0 || ret < 0)
		return (NULL);
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		if (ret < 0)
			return (NULL);
		g.tmp = ft_strjoin(g.save, buff);
		g.save = g.tmp;
	}
	line = ft_strdup(g.save);
	check_double_n(line, all, &g);
	final = ft_split(line, '\n');
	free(g.tmp);
	free(line);
	return (final);
}
