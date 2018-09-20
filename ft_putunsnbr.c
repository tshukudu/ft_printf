/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:49:56 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:03:41 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putunsnbr(unsigned int n)
{
	unsigned int integer;

	integer = n;
	if (integer >= 10)
		ft_putnbr(integer / 10);
	ft_putchar(integer % 10 + 48);
}
