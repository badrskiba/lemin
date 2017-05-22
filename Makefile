# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bskiba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 22:44:28 by bskiba            #+#    #+#              #
#    Updated: 2017/05/10 20:42:53 by bskiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
LIB     = libftprintf/libftprintf.a
NAME    = lem-in
SRCS    = 	srcs/fill_lemin.c\
			srcs/get_code.c\
			srcs/get_links.c\
			srcs/go_to_lastants.c\
			srcs/lemin_fumc.c\
			srcs/main.c\
			srcs/new_lemin.c\
			srcs/verif_lemin.c\
			srcs/ft_affiche.c\
			srcs/get_lemin.c\
			srcs/get_room.c\
			srcs/min_path.c\
			srcs/print_lemin.c\
			srcs/verif_links.c\

OBJS    =   $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			Make -C ./libftprintf
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
		$(RM) $(OBJS)
		Make -C ./libftprintf fclean

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
