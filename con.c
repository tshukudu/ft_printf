/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:48:47 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 10:55:29 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	con(unsigned int i, int b, char frmt, int *len)
{
	if (frmt >= 'a' && frmt <= 'z')
		ft_putstr(convert_bl(i, b), len);
	else
		ft_putstr(convert_bu(i, b), len);
}
