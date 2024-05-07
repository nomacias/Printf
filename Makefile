# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomacias <nomacias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 10:50:33 by nomacias          #+#    #+#              #
#    Updated: 2024/04/11 10:04:19 by nomacias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (Nombre del archivo creado al ejecutar Makefile)
NAME  = libftprintf.a
	
SRCS = ft_printf.c ft_write.c

OFILES  = $(SRCS:.c=.o)
HDR = ft_printf.h

CC = gcc
# Makefile compila todo con gcc usanfo las Flags.
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

#para que no haga relink 
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

# RM -f para que borre los archivos sin confirmar
clean:
	rm -f $(OFILES) 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
