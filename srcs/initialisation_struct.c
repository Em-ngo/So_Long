/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:14:48 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 10:19:43 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_all *all)
{
	all->data.right = 0;
	all->data.down = 0;
	all->data.left = 0;
	all->data.up = 0;
	all->data.collectibles = 0;
	all->win = 0;
	all->moves = 0;
}
