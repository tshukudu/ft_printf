/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:34:02 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 13:50:19 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getflag(char *fo, int *in, t_flags *fl)
{
	while (ft_isflag(fo[*in]))
	{
		if (fo[*in] == '#')
			fl->hash++;
		else if (fo[*in] == '+')
			fl->plus++;
		else if (fo[*in] == '-')
			fl->minus++;
		else if (fo[*in] == '0')
			fl->zero++;
		else if (fo[*in] == ' ')
			fl->space++;
		(*in)++;
	}
}

void	ft_getmod(char *fo, int *in, t_flags *fl)
{
	while (ft_ismod(fo[*in]))
	{
		if (fo[*in] == 'h')
			fl->h++;
		else if (fo[*in] == 'l')
			fl->l++;
		else if (fo[*in] == 'j')
			fl->j++;
		else if (fo[*in] == 'z')
			fl->z++;
		(*in)++;
	}
}
