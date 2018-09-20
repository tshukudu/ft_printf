/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:00:21 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 15:49:00 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	alt(t_flags flag, char f, int *flen, int *k)
{
	if (flag.minus == 0)
		pad(flag.num, flen);
	if ((*k) != 5)
	{
		ft_putchar(f);
		(*flen)++;
	}
	if (flag.minus == 1)
		pad(flag.num, flen);
	(*k) = 0;
}

void	mvp(int *flen, int *k)
{
	ft_putstr("%", flen);
	(*k) = 5;
}

void	gdot(t_flags *flag, char *form, int *c)
{
	flag->dot++;
	(*c)++;
	if (ft_isdigit(form[*c]))
		flag->pre = ft_getnum(form, c, flag);
}

int		abc(char *form, int *c, t_flags *flag, va_list arg)
{
	int flen;
	int k;

	flen = 0;
	if (form[*c] == '%')
		mvp(&flen, &k);
	else if (ft_isdigit(form[*c]) || ft_isflag(form[*c])
			|| ft_isformat(form[*c]) || ft_ismod(form[*c]) || form[*c] == '.')
	{
		if (ft_isflag(form[*c]))
			ft_getflag(form, c, flag);
		if (ft_isdigit(form[*c]))
			flag->num = ft_getnum(form, c, flag);
		if (form[*c] == '.')
			gdot(flag, form, c);
		if (ft_ismod(form[*c]))
			ft_getmod(form, c, flag);
	}
	if (ft_isformat(form[*c]))
		test(form[*c], arg, *flag, &flen);
	else
		alt(*flag, form[*c], &flen, &k);
	return (flen);
}

int		ft_printf(char *format, ...)
{
	va_list	arg;
	int		c;
	int		flen;
	t_flags	flag;

	c = 0;
	flen = 0;
	va_start(arg, format);
	while (format[c])
	{
		ft_initialize(&flag);
		if (format[c] == '%')
		{
			c++;
			if (!format[c])
				break ;
			flen += abc(format, &c, &flag, arg);
		}
		else
			ft_pchar(format[c], &flen);
		c++;
	}
	va_end(arg);
	return (flen);
}
