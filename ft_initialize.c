/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:16:16 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/19 16:30:58 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize(t_flags *fl)
{
	fl->hash = 0;
	fl->dot = 0;
	fl->plus = 0;
	fl->minus = 0;
	fl->zero = 0;
	fl->space = 0;
	fl->h = 0;
	fl->l = 0;
	fl->j = 0;
	fl->z = 0;
	fl->num = 0;
	fl->pre = 0;
}
