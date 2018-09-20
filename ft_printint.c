/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:48:23 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/20 16:44:52 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero(int n, int *sl)
{
	while (--n > 0)
	{
		ft_putchar('0');
		(*sl)++;
	}
}

void	pz(t_flags fla, int *len, char *str)
{
	int k;

	k = 0;
	fla.num -= ft_strlen(str);
	if (fla.plus > 0 && fla.h != 5)
	{
		ft_putchar('+');
		(*len)++;
		k = 5;
	}
	if ((fla.space > 0 && k != 5) && fla.h != 5)
	{
		ft_putchar(' ');
		(*len)++;
	}
	if (fla.h == 5)
	{
		ft_putchar('-');
		(*len)++;
	}
	zero(fla.num, len);
}

void	paddin(char *i, t_flags fla, int *len)
{
	int k;

	k = 0;
	if (fla.zero > 0)
		pz(fla, len, i);
	else
	{
		fla.num -= ft_strlen(i);
		if (fla.minus == 0 && fla.zero == 0)
			space(fla.num, len);
		if (fla.plus > 0 && fla.h != 5)
		{
			ft_putchar('+');
			(*len)++;
			k = 1;
		}
		if ((fla.space > 0 && k != 1) && fla.h != 5)
			ft_putstr("-", len);
		if (fla.h == 5)
			ft_putstr("-", len);
	}
	ft_putstr(i, len);
	if (fla.minus > 0)
		space(fla.num - 1, len);
}

void	neg(long long int *de, t_flags *fla)
{
	if ((*de) < 0)
	{
		(*de) *= -1;
		fla->h = 5;
	}
}

void	ft_printint(va_list arg, char f, t_flags fla, int *len)
{
	long long int	de;
	char			*ptr;

	if (fla.h == 1)
		de = (short)va_arg(arg, int);
	else if (fla.h == 2)
		de = (char)va_arg(arg, int);
	else if (fla.l == 1)
		de = (long)va_arg(arg, long);
	else if (fla.l == 2)
		de = (long long)va_arg(arg, long long);
	else if (fla.j == 1)
		de = (intmax_t)va_arg(arg, intmax_t);
	else if (fla.z == 1)
		de = (size_t)va_arg(arg, size_t);
	else
		de = (long long)va_arg(arg, int);
	neg(&de, &fla);
	if (f >= 'a' && f <= 'z')
		ptr = convert_bl(de, 10);
	else
		ptr = convert_bu(de, 10);
	paddin(ptr, fla, len);
}
