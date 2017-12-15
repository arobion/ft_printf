# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobion <arobion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 16:43:05 by arobion           #+#    #+#              #
#    Updated: 2017/12/15 15:34:16 by arobion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = 	ft_unicode.c \
		ft_count_unsigned_var.c \
		ft_atoi.c \
		ft_iswp.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_wputchar.c \
		ft_strcap.c \
		ft_isdigit.c \
		ft_long_itoa.c \
		ft_unsigned_itoa.c \
		ft_strlen.c \
		ft_memalloc.c \
		ft_strcpy.c \
		ft_strcpy_p.c \
		ft_ctoi.c \
		ft_memset.c \
		ft_strdup.c \
		ft_decim.c \
		ft_strnew.c \
		ft_convert_o.c \
		ft_convert_u.c \
		ft_convert_i.c \
		ft_convert_d.c \
		ft_convert_x.c \
		ft_convert_x2.c \
		ft_convert_p.c \
		ft_convert_c.c \
		ft_convert_c2.c \
		ft_convert_s.c \
		ft_convert_smaj.c \
		ft_convert_smaj2.c \
		ft_s_bis.c \
		ft_s_bis2.c \
		ft_smaj_bis.c \
		ft_smaj_bis2.c \
		ft_remp.c \
		ft_remp2.c \
		ft_remp3.c \
		ft_unsigned_remp.c \
		ft_unsigned_remp2.c \
		printf.c \
		printf2.c \
		ft_verif_before_print.c \
		select.c \
		select2.c \
		select3.c \
		select4.c \
		select5.c \
		ft_base_remp.c \
		ft_base_remp2.c \
		ft_base_remp3.c \
		ft_s_remp.c \
		ft_smaj_remp.c \
		ft_split_printf.c \
		ft_split_printf2.c \
		ft_split_printf3.c 

OBJ = $(SRC:.c=.o)

INCLUDES = .

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)PRINTF READY$(END)"

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	@echo "$(RED)FT_PRINTF OBJECTS REMOVE$(END)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)FT_PRINTF REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
