/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:46:05 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 10:59:44 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(va_list arg, t_flags fla, int *len)
{
	char c;

	if (fla.minus == 0)
		while (--fla.num > 0)
		{
			ft_putchar(' ');
			(*len)++;
		}
	c = va_arg(arg, int);
	ft_putchar(c);
	(*len)++;
	if (fla.minus > 0)
		while (--fla.num > 0)
		{
			ft_putchar(' ');
			(*len)++;
		}
}
