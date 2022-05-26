# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 21:20:50 by abayar            #+#    #+#              #
#    Updated: 2022/05/26 18:02:43 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c ft_atoi.c philo.c

NAME = philo

FLAGS = gcc -Wall -Wextra -Werror -pthread

all : ${NAME}

${NAME} : ${SRC}
	@${FLAGS} ${SRC} -o ${NAME}

clean	:
	@rm -f ${NAME}

fclean	: clean

re		: fclean all
