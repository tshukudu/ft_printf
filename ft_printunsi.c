/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:51:12 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:02:06 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printunsi(va_list arg, t_flags fla, int *len)
{
	unsigned int i;

	i = va_arg(arg, unsigned int);
	if (fla.dot == 1)
		while (--fla.num > 1)
		{
			ft_putchar('0');
			(*len)++;
		}
	if (fla.minus == 0)
		while (--fla.num > 0)
		{
			ft_putchar(' ');
			(*len)++;
		}
	ft_putunsnbr(i);
	(*len)++;
	if (fla.minus > 0)
		while (--fla.num > 0)
		{
			ft_putchar(' ');
			(*len)++;
		}
}
