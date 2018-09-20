/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:53:21 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:01:34 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printss(va_list arg, int *len)
{
	long int	i;
	wchar_t		*ws;
	char		s[10];
	wchar_t		wc;
	int			j;

	j = 0;
	i = 0;
	ws = va_arg(arg, wchar_t *);
	while (ws[i])
	{
		wc = ws[i];
		ft_unicode(wc, s);
		ft_putstr(s, &j);
		(*len)++;
		i++;
	}
}
