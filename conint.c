/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:48:05 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 10:56:00 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conint(long long int i, int b, char f, int *len)
{
	if (i < 0)
	{
		i = -i;
		ft_putchar('-');
		(*len)++;
	}
	if (f >= 'a' && f <= 'z')
		ft_putstr(convert_bl(i, b), len);
	else
		ft_putstr(convert_bu(i, b), len);
}
