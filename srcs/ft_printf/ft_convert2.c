/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:45 by engo              #+#    #+#             */
/*   Updated: 2022/11/14 10:28:14 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upper_x(va_list convert, t_struct *j)
{
	unsigned int	k;

	k = va_arg(convert, unsigned int);
	ft_putnbr_base(k, "0123456789ABCDEF", j);
}

void	ft_low_x(va_list convert, t_struct *j)
{
	unsigned int	k;

	k = va_arg(convert, unsigned int);
	ft_putnbr_base(k, "0123456789abcdef", j);
}

void	ft_putp(unsigned long nb, char *base, t_struct *j)
{
	if (nb < 1)
		nb *= -1;
	if (nb % 16 != nb)
		ft_putp(nb / 16, base, j);
	ft_putchar(base[nb % 16], j);
}

void	ft_p(va_list convert, t_struct *j)
{
	unsigned long	s;

	s = va_arg(convert, unsigned long);
	ft_putchar('0', j);
	ft_putchar('x', j);
	ft_putp(s, "0123456789abcdef", j);
}
