# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguilbea <gguilbea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 19:51:54 by gguilbea          #+#    #+#              #
#    Updated: 2022/10/05 19:51:56 by gguilbea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = *.c

all: $(NAME)
$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
