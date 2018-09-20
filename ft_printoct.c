/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:50:18 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/20 16:40:18 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octspace(int n, int *sl)
{
	while (--n > 0)
	{
		ft_putchar(' ');
		(*sl)++;
	}
}

void	octzero(int n, int *sl)
{
	n++;
	while (--n > 0)
	{
		ft_putchar('0');
		(*sl)++;
	}
}

void	octpz(t_flags fla, int *len, char *i)
{
	fla.num -= ft_strlen(i);
	if (fla.pre > 0)
		octzero(fla.num, len);
	if (i[0] != '0' && fla.hash > 0)
	{
		ft_putchar('0');
		(*len)++;
	}
}

void	octpaddin(char *i, t_flags fla, int *len)
{
	if (fla.hash > 0 && i[0] != '0')
		fla.num -= 1;
	if (fla.pre >= fla.num || fla.zero > 0)
		octpz(fla, len, i);
	else
	{
		fla.num -= ft_strlen(i) - 1;
		if (fla.minus == 0 && fla.zero == 0)
			octspace(fla.num, len);
		if (i[0] != '0' && fla.hash > 0)
		{
			ft_putchar('0');
			(*len)++;
			fla.num--;
		}
	}
	ft_putstr(i, len);
	if (fla.num >= fla.pre)
		octspace(fla.num, len);
}

void	ft_printoct(va_list arg, char g, t_flags fla, int *len)
{
	long	int	i;
	char		*ptr;

	if (fla.h == 1)
		i = (unsigned short)va_arg(arg, unsigned int);
	else if (fla.h == 2)
		i = (unsigned char)va_arg(arg, unsigned int);
	else if (fla.l == 1)
		i = (unsigned long int)va_arg(arg, unsigned long int);
	else if (fla.l == 2)
		i = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (fla.j == 1)
		i = (int)va_arg(arg, int);
	else if (fla.z == 1)
		i = (size_t)va_arg(arg, size_t);
	else
		i = va_arg(arg, unsigned int);
	if (g >= 'a' && g <= 'z')
		ptr = convert_bl(i, 8);
	else
		ptr = convert_bu(i, 8);
	octpaddin(ptr, fla, len);
}
