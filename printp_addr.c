/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:46:26 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:05:00 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef	unsigned	long	int	t_uintptr;

void		printp_addr(void *ptr, int *len)
{
	t_uintptr	j;
	char		lst[16];
	char		*p;

	j = (t_uintptr)ptr;
	p = &lst[16];
	*--p = '\0';
	while (p > lst)
	{
		*--p = "0123456789abcdef"[j % 16];
		j /= 16;
	}
	while (*p == '0')
		++p;
	ft_putstr("0x", len);
	ft_putstr(p, len);
}
