/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:53:01 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:01:18 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printspc(va_list arg, t_flags fl, int *len)
{
	wint_t	wc;
	char	s[5];

	wc = va_arg(arg, unsigned int);
	ft_unicode(wc, s);
	if (fl.minus == 0)
		while (--fl.num > 2)
		{
			ft_putchar(' ');
			(*len)++;
		}
	ft_putstr(s, len);
	if (fl.minus > 0)
		while (--fl.num > 2)
		{
			ft_putchar(' ');
			(*len)++;
		}
}
