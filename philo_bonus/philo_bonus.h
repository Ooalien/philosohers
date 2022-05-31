/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:07:41 by abayar            #+#    #+#             */
/*   Updated: 2022/05/30 15:09:33 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_data
{
    sem_t   *fork;
    sem_t   print;
    size_t  nph;
    size_t  t_die;
    size_t  t_eat;
    size_t  t_sleep;
    size_t  n_meals;
    size_t  meals;
    

}	t_data;

int	is_num(char *s);
int	check_args(char **av);
int	ft_atoi(const char *str);

#endif