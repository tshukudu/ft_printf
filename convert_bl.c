/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:47:39 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 15:25:16 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_bl(long long int num, int base)
{
	static char	representation[] = "0123456789abcdef";
	static char	buffer[50];
	char		*ptr;
	int			r;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	if (num < 0)
	{
		if (base == 10)
			*--ptr = '-';
		num *= -1;
	}
	while (num != 0)
	{
		r = num % base;
		*--ptr = representation[r];
		num /= base;
	}
	return (ptr);
}
