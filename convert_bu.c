/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:47:05 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 15:21:07 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_bu(long long int num, int base)
{
	static char	representation[] = "0123456789ABCDEF";
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
