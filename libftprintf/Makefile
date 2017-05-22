# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bskiba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 12:30:54 by bskiba            #+#    #+#              #
#    Updated: 2017/05/10 17:18:11 by bskiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJET_NAME = $(SRC_NAME:.c=.o)
PATH_INC = ./includes
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC_NAME =  ft_isdigit.c ft_memcpy.c ft_strclr.c ft_striteri.c \
			ft_strncat.c ft_strrchr.c ft_atoi.c ft_isprint.c \
			ft_memdel.c ft_strcmp.c ft_strjoin.c ft_strncmp.c \
			ft_strstr.c ft_bzero.c ft_memalloc.c ft_memmove.c \
			ft_strcpy.c ft_strlcat.c ft_strncpy.c ft_strsub.c \
			ft_isalnum.c ft_memccpy.c ft_memset.c ft_strdel.c \
			ft_strlen.c ft_strnequ.c ft_strtrim.c ft_isalpha.c \
			ft_memchr.c ft_strcat.c ft_strequ.c ft_strmap.c \
			ft_strnew.c ft_isascii.c ft_memcmp.c ft_strchr.c \
			ft_striter.c ft_strmapi.c ft_strnstr.c ft_strdup.c \
			ft_toupper.c ft_tolower.c ft_swapchar.c ft_swapint.c\
			ft_lst_count_elem.c ft_lstpush.c ft_lstmap.c ft_lstiter.c\
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c\
			ft_itoa.c ft_strsplit.c ft_putnbr.c ft_putnbr_fd.c \
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
			ft_putstr.c ft_putstr_fd.c ft_display_file.c\
			handle_flags.c handle_unicode.c  print_uint_frontwidth.c\
			print_int_endwidth.c print_pourcent.c  printf_itoa_base_octal.c\
			ft_itoa_uintmax.c handle_lenght.c handle_width.c  print_chr.c\
			print_int_frontwidth.c print_str.c printf_strlower.c\
			ft_printf.c handle_precision.c  print_hex.c\
			print_normal_str.c print_widestr.c read_format.c\
			handle_type.c print_uint_endwidth.c print_int.c print_octal.c\
			printf_itoa_base.c ft_itoa_intmax.c print_wint.c\
			print_hex_frontwidth.c print_hex_endwidth.c\
			print_octal_frontwidth.c get_next_line.c\

all: $(NAME)

$(NAME) : $(OBJET_NAME)
	ar r $(NAME) $(OBJET_NAME)

%.o : %.c
	$(CC) $(FLAGS) -c -I $(PATH_INC) $<

clean:
	rm -rf $(SRC_NAME:.c=.o)

fclean: clean
	rm -rf $(NAME);

re: fclean all

