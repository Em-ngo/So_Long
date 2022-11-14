/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:31:00 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 10:28:54 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_struct *j)
{
	write(1, &c, 1);
	j->g_return++;
}

void	ft_putnbr_fd(int n, t_struct *j)
{
	if (n < 0)
	{
		ft_putchar('-', j);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			j->g_return += 10;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, j);
		ft_putnbr_fd(n % 10, j);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0', j);
}

void	ft_putnbr_unsigned(unsigned int n, t_struct *j)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, j);
		ft_putnbr_fd(n % 10, j);
	}
	else if (n >= 1 && n <= 9)
		ft_putchar(n + '0', j);
}

void	ft_putnbr_base(unsigned int nbr, char *base, t_struct *j)
{
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(base);
	if (nbr < 1)
	{
		ft_putchar('-', j);
		i = (unsigned int)(-nbr);
	}
	else
		i = (unsigned int)nbr;
	if (i >= size)
	{
		ft_putnbr_base(i / size, base, j);
		ft_putnbr_base(i % size, base, j);
	}
	else
		ft_putchar(base[i % size], j);
}
