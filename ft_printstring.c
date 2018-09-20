/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:52:24 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/20 16:43:25 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p(char f, int *l)
{
	ft_putchar(f);
	(*l)++;
}

void	ele(char *s, t_flags f, int *len)
{
	if (!f.minus)
		while (--f.num >= ft_strlen(s))
			!(f.zero) ? p(' ', len) : p('0', len);
	ft_putstr(s, len);
	while (--f.num >= ft_strlen(s))
		!(f.minus) ? 0 : p(' ', len);
}

void	ft_printstring(va_list arg, t_flags f, int *len)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(arg, char *);
	if (f.dot == 1)
	{
		if (!f.minus)
			while (--f.num >= f.pre)
				!(f.zero) ? p(' ', len) : p('0', len);
		while (i < f.pre && s)
		{
			ft_putchar(s[i]);
			(*len)++;
			i++;
		}
		while (--f.num >= f.pre)
			!(f.minus) ? 0 : p(' ', len);
	}
	else
		ele(s, f, len);
}
