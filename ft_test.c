/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:43:44 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:04:23 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test(char format, va_list arg, t_flags flag, int *flen)
{
	if (format == 'c')
		ft_printchar(arg, flag, flen);
	else if (format == 'S')
		ft_printss(arg, flen);
	else if (format == 'p')
		ft_printp(arg, flen, flag);
	else if (format == 'd' || format == 'i' || format == 'D')
		ft_printint(arg, format, flag, flen);
	else if (format == 'o' || format == 'O')
		ft_printoct(arg, format, flag, flen);
	else if (format == 'u' || format == 'U')
		ft_printunsi(arg, flag, flen);
	else if (format == 'x' || format == 'X')
		ft_printhex(arg, format, flag, flen);
	else if (format == 'C')
		ft_printspc(arg, flag, flen);
	else if (format == 's')
		ft_printstring(arg, flag, flen);
}
