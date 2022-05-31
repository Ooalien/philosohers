/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:05:57 by abayar            #+#    #+#             */
/*   Updated: 2022/05/31 18:37:37 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	timenow(void)
{
	struct timeval	time;
	size_t			t;

	t = 0;
	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}

void	mysleep(size_t time)
{
	long	i;
	size_t		j;	

	i = timenow();
	j = (time * 1000) - 20000;
	usleep(j);
	while (timenow() - i < (unsigned long)time)
		;
}

void	creatsema(t_data *data)
{
	unlink("forks");
	unlink("print");
	data->print = sem_open("print", O_CREAT, 0644, 1);
	data->forks = sem_open("forks", O_CREAT, 0644, data->nph);
	if (data->forks == SEM_FAILED || data->print == SEM_FAILED)
	{
		printf("semaphore fail\n");
		exit(1);
	}
}

int	read_data(int ac, char **av, t_data *data)
{
	data->end = 0;
	data->nph = ft_atoi(av[1]);
	if (data->nph < 1)
		return (-1);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->n_meal = ft_atoi(av[5]);
		if (data->n_meal == 0)
			return (-1);
	}
	else
		data->n_meal = -1;
	creatsema(data);
	return (0);
}

void	to_do(t_data *data, int index)
{
	if (index == 1)
	{
		//data->eating = 1;
		data->last_meal = timenow();
		mysleep(data->t_eat);
		//data->eating = 0;
		// if (++data->meals >= data->n_meal && data->n_meal != -1)
		// 	data->end++;
	}
	else if (index == 2)
		mysleep(data->t_sleep);
}

void	print(t_data *data, int index)
{
	sem_wait(data->print);
	if (index == 0)
		printf("%zu %zu has taken a fork\n", timenow() - data->start, data->id);
	else if (index == 1)
		printf("%zu %zu is eating\n", timenow() - data->start, data->id);
	else if (index == 2)
		printf("%zu %zu is sleeping\n", timenow() - data->start, data->id);
	else if (index == 3)
		printf("%zu %zu is thinking\n", timenow() - data->start, data->id);
	sem_post(data->print);
	to_do(data, index);
}

void	*check_dead(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	// while (1)
	// {
		
	// }
	return (NULL);
}

void	take_fork(t_data *data)
{
	sem_wait(data->forks);
	print(data, 0);
	sem_wait(data->forks);
	print(data, 0);
}

void	routine(t_data *data)
{
	pthread_t ph;

	data->start = timenow();
	data->last_meal = timenow();
	pthread_create(&ph, NULL, check_dead, data);
	if (data->id % 2 == 0)
		usleep(100);
	while (1)
	{
		take_fork(data);
		print(data, 1);
		sem_post(data->forks);
		sem_post(data->forks);
		print(data, 2);
		print(data, 3);
	}
}

void	creat_philos(t_data *data)
{
	data->id = 0;
	data->pid = malloc(sizeof(pid_t) * data->nph);
	if (!data->pid)
	{
		printf("malloc fail\n");
		exit(1);
	}
	while (data->id < data->nph)
	{
		data->pid[data->id] = fork();
		if (data->pid[data->id] == -1)
		{
			printf("fork fail\n");
		}
		if (data->pid[data->id] == 0)
			routine(data);
		//usleep(100);
		data->id++;
	}
}

int main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		if (check_args(av) == 0)
		{
			write(2, "Error args\n", 11);
			return (1);
		}
		if (read_data(ac, av, data) == -1)
		{
			printf("Error\n");
			return (1);
		}
		creat_philos(data);
	}
	else
		
	return (0);
}