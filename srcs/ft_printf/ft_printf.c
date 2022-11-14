/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:55 by engo              #+#    #+#             */
/*   Updated: 2021/10/14 15:31:33 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent(const char *str, va_list convert, int i, t_struct *j)
{
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_d_i(convert, j);
	if (str[i + 1] == 'c')
		ft_c(convert, j);
	if (str[i + 1] == 's')
		ft_s(convert, j);
	if (str[i + 1] == 'u')
		ft_u(convert, j);
	if (str[i + 1] == 'p')
		ft_p(convert, j);
	if (str[i + 1] == 'x')
		ft_low_x(convert, j);
	if (str[i + 1] == 'X')
		ft_upper_x(convert, j);
	if (str[i + 1] == '%')
		ft_putchar('%', j);
}

static void	vf_print(const char *str, va_list convert, t_struct *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_percent(str, convert, i, j);
			i++;
		}
		else
			ft_putchar(str[i], j);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		convert;
	t_struct	j;

	j.g_return = 0;
	va_start(convert, str);
	vf_print(str, convert, &j);
	va_end(convert);
	return (j.g_return);
}
