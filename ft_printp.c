/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:46:47 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:10:30 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sspace(int n, int *j)
{
	n = n - 14;
	while (--n > 0)
	{
		ft_putchar(' ');
		(*j)++;
	}
}

void	ft_printp(va_list arg, int *len, t_flags f)
{
	void	*p;

	p = va_arg(arg, void *);
	sspace(f.num, len);
	printp_addr(p, len);
}
