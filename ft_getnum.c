/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:30:10 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 10:58:24 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getnum(char *f, int *i, t_flags *fi)
{
	int		p;
	int		n;
	char	nb[18];

	p = 0;
	if (f[*i] == '.')
	{
		fi->dot++;
		(*i)++;
	}
	while (ft_isdigit(f[*i]))
	{
		nb[p] = f[*i];
		p++;
		(*i)++;
	}
	nb[p] = '\0';
	n = ft_atoi(&nb[0]);
	return (n);
}
