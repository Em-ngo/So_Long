/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:06:10 by engo              #+#    #+#             */
/*   Updated: 2022/09/28 10:24:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <string.h>

static char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

static char	*find_return(char **str)
{
	int		i;
	char	*s1;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	s1 = ft_substr(*str, 0, i + 1);
	if (s1 == NULL)
		return (NULL);
	if ((*str)[i] == '\n' && (*str)[i + 1] != '\0')
	{
		tmp = ft_strdup(&(*str)[i + 1]);
		if (!tmp)
			return (NULL);
	}
	else
		tmp = NULL;
	free(*str);
	*str = tmp;
	if (!*str && s1[0] == '\0')
		return (ft_free(s1));
	return (s1);
}

static int	find_line_2(char **str, char **buff)
{
	char	*tmp;

	tmp = ft_strjoin(*str, *buff);
	free(*str);
	if (tmp == NULL)
		return (1);
	*str = tmp;
	return (0);
}

static int	find_line(int fd, char **str, char **buff)
{
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, *buff, BUFFER_SIZE);
		(*buff)[i] = '\0';
		if (!*str || !**str)
		{
			*str = ft_strdup(*buff);
			if (*str == NULL)
				return (1);
		}
		else
		{
			if (find_line_2(str, buff))
				return (1);
		}
		if (ft_check (*str, '\n'))
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, "", 0) == -1)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (find_line(fd, &str, &buff))
	{
		free (buff);
		return (NULL);
	}
	free (buff);
	return (find_return(&str));
}
