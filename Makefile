# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 21:20:50 by abayar            #+#    #+#              #
#    Updated: 2022/05/26 16:09:49 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo/check_error.c philo/ft_atoi.c philo/philo.c

SRCB = 

NAME = philoo

NAMEB = philoo_bonus

FLAGS = gcc -Wall -Wextra -Werror -pthread

all : ${NAME}

bonus : ${NAMEB}

${NAME} : ${SRC}
	@${FLAGS} ${SRC} -o ${NAME}

${NAMEB} : ${SRCB}
	@${FLAGS} ${SRCB} -o ${NAMEB}

clean	:
	@rm -f ${NAME}
	@rm -f ${NAMEB}

fclean	: clean

re		: fclean all
