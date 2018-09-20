/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:44:59 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 14:13:54 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	int i;
	int n;

	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
	(*len) += n;
}

void	ft_pchar(char f, int *flen)
{
	ft_putchar(f);
	(*flen)++;
}
