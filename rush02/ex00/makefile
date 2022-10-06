# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oletourn <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 11:43:16 by oletourn          #+#    #+#              #
#    Updated: 2022/10/02 11:43:30 by oletourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = ft_atoi.c ft_complementaire.c ft_complementaire2.c ft_complementaire3.c ft_is_good.c ft_is_good2.c ft_is_good3.c main.c

all = $(NAME)

rush-02:
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all