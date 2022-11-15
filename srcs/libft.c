/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:30:24 by engo              #+#    #+#             */
/*   Updated: 2022/11/15 10:43:35 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *)s;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == (unsigned char) c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	while ((s1[a] != 0) && (s2 != 0) && (s1[a] == s2[a]) && (a < n - 1))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
