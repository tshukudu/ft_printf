/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:49:13 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 15:47:16 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	long int	integer;

	integer = (long int)n;
	if (integer < 0)
	{
		ft_putchar('-');
		integer *= -1;
	}
	if (integer >= 10)
		ft_putnbr(integer / 10);
	ft_putchar(integer % 10 + 48);
}

void	pad(int n, int *counter)
{
	while (--n > 0)
	{
		ft_putchar(' ');
		(*counter)++;
	}
}
