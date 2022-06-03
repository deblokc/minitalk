# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:57:09 by tnaton            #+#    #+#              #
#    Updated: 2022/01/14 12:29:30 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath ft_%.c libft 
vpath %.h libft
vpath ft_%.o libft

NAME = minitalk

LIBFT = libft/libft.a

objects = client server

$(NAME) : $(objects)

$(objects): %: %.c $(LIBFT) minitalk.h
	gcc $< $(LIBFT) -o $@

-include libft/Makefile

ft_%.o : ft_%.c 
	gcc -c $< -o $@

$(LIBFT) : $(SRCS) libft.h
	$(MAKE) all -C ./libft

.PHONY: all
all : $(objects)

.PHONY: clean
clean : 
	$(MAKE) clean -C ./libft

.PHONY: fclean
fclean :
	rm -rf $(objects)
	$(MAKE) fclean -C ./libft

.PHONY: re
re : fclean minitalk 
