/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:52:12 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 11:04:36 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	e(unsigned int code, char temp[5])
{
	temp[3] = 0x80 | (code & 0x3F);
	code = (code >> 6);
	temp[2] = 0x80 | (code & 0x3F);
	code = (code >> 6);
	temp[1] = 0x80 | (code & 0x3F);
	code = (code >> 6);
	temp[0] = 0xF0 | (code & 0x7);
	temp[4] = '\0';
}

void	d(unsigned int code, char temp[5])
{
	temp[2] = 0x80 | (code & 0x3F);
	code = (code >> 6);
	temp[1] = 0x80 | (code & 0x3F);
	code = (code >> 6);
	temp[0] = 0xE0 | (code & 0xF);
	temp[3] = '\0';
}

void	ft_unicode(unsigned int code, char temp[5])
{
	if (code <= 0x7F)
	{
		temp[0] = (code & 0x7F);
		temp[1] = '\0';
	}
	else if (code <= 0x7FF)
	{
		temp[1] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[0] = 0xC0 | (code & 0x1F);
		temp[2] = '\0';
	}
	else if (code <= 0xFFFF)
		d(code, temp);
	else if (code <= 0x10FFFF)
		e(code, temp);
	else
	{
		temp[2] = 0xEF;
		temp[1] = 0xBF;
		temp[0] = 0xBD;
		temp[3] = '\0';
	}
}
