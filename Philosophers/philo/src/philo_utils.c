/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:13:28 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/27 14:39:30 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uint64_t	ft_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_philo_init(t_philo **philo)
{
	pthread_mutex_t	tmp;

	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!*philo)
		return (1);
	(*philo)->die = 0;
	(*philo)->p_nbr = 0;
	(*philo)->sleep = 0;
	(*philo)->eat = 0;
	(*philo)->must_eat_flag = -1;
	(*philo)->dead_flag = 0;
	(*philo)->start_time = ft_time();
	(*philo)->list = NULL;
	(*philo)->forks = NULL;
	pthread_mutex_init(&tmp, NULL);
	(*philo)->message = tmp;
	pthread_mutex_init(&tmp, NULL);
	(*philo)->check_dead = tmp;
	pthread_mutex_lock(&(*philo)->check_dead);
	(*philo)->total_eat = 0;
	(*philo)->must_eat_search = 0;
	return (0);
}

void	*must_eat(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (philo->dead_flag == 0 && philo->must_eat_search == 0)
	{
		if (philo->total_eat == philo->p_nbr)
		{
			philo->must_eat_search = 1;
			printf("%llu \033[1;34mEverybody has eaten %d times senpai!\n",
				ft_time() - philo->start_time, philo->must_eat_flag);
			pthread_mutex_unlock(&(philo->check_dead));
			return ((void *)0);
		}
	}
	return ((void *)0);
}

void	*ft_death_control(void *cur_p)
{
	t_plist	*cur_philo;

	cur_philo = (t_plist *)cur_p;
	while (cur_philo->philo_struct->dead_flag == 0
		&& cur_philo->philo_struct->must_eat_search == 0)
	{
		if ((cur_philo->eating == 0)
			&& (ft_time() - cur_philo->last_eat)
			> cur_philo->philo_struct->die)
		{
			print_message(cur_philo, " \033[1;31mis dead\033[0;0m\n");
			cur_philo->philo_struct->dead_flag = 1;
			pthread_mutex_unlock(&(cur_philo->philo_struct->check_dead));
			return ((void *)0);
		}
		usleep(1000);
	}
	pthread_mutex_unlock(&(cur_philo->philo_struct->check_dead));
	return ((void *)0);
}

void	*ft_live(void *cur_p)
{
	t_plist		*cur_philo;
	pthread_t	thread;

	cur_philo = (t_plist *)cur_p;
	cur_philo->last_eat = ft_time();
	if (pthread_create(&thread, NULL, &ft_death_control, cur_p) != 0)
		return ((void *)0);
	pthread_detach(thread);
	while (cur_philo->philo_struct->dead_flag == 0
		&& cur_philo->philo_struct->must_eat_search == 0)
	{
		lock_fork(cur_philo);
		eat(cur_philo);
		unlock_fork(cur_philo);
		print_message(cur_philo, "is thinking\n");
	}
	return ((void *)0);
}
