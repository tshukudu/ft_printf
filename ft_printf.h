/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:51:20 by mtshukud          #+#    #+#             */
/*   Updated: 2018/08/20 16:51:23 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <locale.h>
# include <wchar.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int					ft_strlen(char *str);
int					ft_isdigit(int c);
int					ft_isformat(char f);
void				ft_putchar(char c);
void				ft_putstr(char *s, int *len);
char				*convert_bu(long long int num, int base);
char				*convert_bl(long long int num, int base);
void				conint(long long int i, int b, char f, int *len);
void				con(unsigned int i, int b, char frmt, int *len);
void				ft_putnbr(int n);
void				ft_putunsnbr(unsigned int n);
void				ft_unicode(unsigned int code, char temp[5]);
void				ft_printss(va_list arg, int *len);
int					ft_printf(char *format, ...);
int					ft_atoi(const char *str);
int					ft_isflag(char f);

typedef	struct		s_flags
{
	int	hash;
	int space;
	int dot;
	int plus;
	int	minus;
	int zero;
	int	h;
	int l;
	int j;
	int z;
	int num;
	int pre;
}					t_flags;

void				ft_getflag(char *fo, int *in, t_flags *fl);
void				ft_printstring(va_list arg, t_flags f, int *len);
void				ft_printint(va_list arg, char f, t_flags fl, int *len);
void				ft_printoct(va_list arg, char g, t_flags fla, int *len);
void				ft_printunsi(va_list arg, t_flags f, int *len);
void				ft_printhex(va_list arg, char f, t_flags fl, int *len);
void				ft_printchar(va_list arg, t_flags fla, int *len);
void				ft_printspc(va_list arg, t_flags fl, int *len);
void				ft_initialize(t_flags *flag);
int					ft_digitsno(long long int i);
void				printp_addr(void *ptr, int *len);
void				ft_printp(va_list arg, int *len, t_flags f);
void				test(char format, va_list arg, t_flags flag, int *flen);
int					ft_ismod(char f);
void				ft_getmod(char *fo, int *in, t_flags *fl);
int					ft_getnum(char *f, int *i, t_flags *fi);
void				space(int n, int *sl);
void				ft_pchar(char f, int *flen);
void				pad(int n, int *counter);
#endif
