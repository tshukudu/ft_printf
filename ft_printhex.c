/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:51:44 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/20 11:30:06 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexspace(int n, int *sl)
{
	while (--n > 0)
	{
		ft_putchar(' ');
		(*sl)++;
	}
}

void	hexzero(int n, int *sl)
{
	n++;
	while (--n > 0)
	{
		ft_putchar('0');
		(*sl)++;
	}
}

void	hexpz(t_flags fla, int *len, char *i, char f)
{
	fla.num -= ft_strlen(i) - 1;
	if (fla.hash > 0 && i[0] != '0')
	{
		if (f >= 'a' && f <= 'z')
			ft_putstr("0x", len);
		else
			ft_putstr("0X", len);
	}
	if (fla.minus == 0)
		hexzero(fla.num, len);
}

void	hexpaddin(char *i, t_flags fla, int *len, char f)
{
	if (fla.hash > 0 && i[0] != '0')
		fla.num -= 2;
	if (fla.zero > 0)
		fla.num--;
	if (fla.zero > 0)
		hexpz(fla, len, i, f);
	else
	{
		fla.num -= ft_strlen(i) - 1;
		if (fla.minus <= 0)
			hexspace(fla.num, len);
		if (fla.hash > 0 && i[0] != '0')
		{
			if (f >= 'a' && f <= 'z')
				ft_putstr("0x", len);
			else
				ft_putstr("0X", len);
		}
	}
	ft_putstr(i, len);
	if (fla.minus > 0)
		hexspace(fla.num, len);
}

void	ft_printhex(va_list arg, char f, t_flags fla, int *flen)
{
	unsigned long long	i;
	char				*ptr;

	if (fla.h == 1)
		i = (unsigned short)va_arg(arg, unsigned int);
	else if (fla.h == 2)
		i = (unsigned char)va_arg(arg, unsigned int);
	else if (fla.l == 1)
		i = (unsigned long long int)va_arg(arg, unsigned long int);
	else if (fla.l == 2)
		i = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (fla.j == 1)
		i = (uintmax_t)va_arg(arg, uintmax_t);
	else if (fla.z == 1)
		i = (size_t)va_arg(arg, size_t);
	else
		i = va_arg(arg, unsigned int);
	if (f >= 'a' && f <= 'z')
		ptr = convert_bl(i, 16);
	else
		ptr = convert_bu(i, 16);
	hexpaddin(ptr, fla, flen, f);
}
