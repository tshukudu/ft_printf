# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 08:14:35 by mtshukud          #+#    #+#              #
#    Updated: 2018/08/18 03:47:15 by mtshukud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG  = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = con.c\
	  conint.c\
	  convert_bl.c\
	  convert_bu.c\
	  ft_isdigit.c\
	  ft_isformat.c\
	  ft_printchar.c\
	  ft_printhex.c\
	  ft_printint.c\
	  ft_printoct.c\
	  ft_printp.c\
	  ft_printspc.c\
	  ft_printss.c\
	  ft_printunsi.c\
	  ft_putchar.c\
	  ft_putnbr.c\
	  ft_putstr.c\
	  ft_putunsnbr.c\
	  ft_strlen.c\
	  ft_unicode.c\
	  printp_addr.c\
	  ft_printstring.c\
	  ft_printf.c\
	  ft_atoi.c\
	  ft_isflag.c\
	  ft_getnum.c\
	  ft_getflag.c\
	  ft_initialize.c\
	  ft_digitsno.c\
	  ft_test.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean , flcean, re
