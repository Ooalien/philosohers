/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:07:41 by abayar            #+#    #+#             */
/*   Updated: 2022/05/31 18:20:16 by abayar           ###   ########.fr       */
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
    pid_t   *pid;
    sem_t   *forks;
    sem_t   *print;
    size_t  id;
    size_t  nph;
    size_t  t_die;
    size_t  t_eat;
    size_t  t_sleep;
    size_t  start;
    size_t  last_meal;
    size_t  n_meal;
    size_t  meals;
    size_t  end;

}	t_data;

int	is_num(char *s);
int	check_args(char **av);
int	ft_atoi(const char *str);

#endif