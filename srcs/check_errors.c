/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:01 by engo              #+#    #+#             */
/*   Updated: 2022/10/20 16:32:04 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_first_last_line(char *line, t_error *error)
{
	int		i;

	i = 0;
	if (ft_strlen(line[i]) == ft_strlen(line[i][j]))
		error->shape = 1;
	while (line[i])
	{
		if (line[i] != '1')
		error->closed = 1;
	i++;
	}
	all->row = i;
}

