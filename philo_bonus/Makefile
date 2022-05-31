# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 18:05:14 by abayar            #+#    #+#              #
#    Updated: 2022/05/30 15:13:30 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c ft_atoi.c philo_bonus.c

NAME = philo_bonus

FLAGS = gcc -Wall -Wextra -Werror -pthread

all : ${NAME}

${NAME} : ${SRC}
	@${FLAGS} ${SRC} -o ${NAME}

clean	:
	@rm -f ${NAME}

fclean	: clean

re		: fclean all
