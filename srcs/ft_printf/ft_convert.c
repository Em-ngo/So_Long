/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:38 by engo              #+#    #+#             */
/*   Updated: 2021/10/14 15:31:28 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_i(va_list convert, t_struct *j)
{
	int	result;

	result = va_arg(convert, int);
	ft_putnbr_fd(result, j);
}

void	ft_c(va_list convert, t_struct *j)
{
	int	c;

	c = va_arg(convert, int);
	write(1, &c, 1);
	j->g_return++;
}

void	ft_s(va_list convert, t_struct *j)
{
	char	*s;

	s = va_arg(convert, char *);
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, j);
		s++;
	}
}

void	ft_u(va_list convert, t_struct *j)
{
	unsigned int	result;

	result = va_arg(convert, unsigned int);
	ft_putnbr_unsigned(result, j);
}
