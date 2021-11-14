/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:23:49 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/30 18:53:43 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fork_creator(t_philo *philo)
{
	pthread_mutex_t	*m_arr;
	pthread_mutex_t	tmp;
	int				i;

	m_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (philo->p_nbr + 1));
	if (!m_arr)
		return (0);
	i = 0;
	while (philo->p_nbr + 1 > i)
	{
		pthread_mutex_init(&tmp, NULL);
		m_arr[i++] = tmp;
	}
	philo->forks = m_arr;
	return (1);
}

void	lock_fork(t_plist *cur_philo)
{
	if (cur_philo->philo_struct->p_nbr > 1)
	{
		pthread_mutex_lock(&cur_philo->philo_struct
			->forks[cur_philo->left_fork]);
		print_message(cur_philo, "Took the left fork\n");
		pthread_mutex_lock(&cur_philo->philo_struct->forks
		[cur_philo->right_fork]);
		print_message(cur_philo, "Took the right fork\n");
	}
}

void	unlock_fork(t_plist *cur_philo)
{
	if (cur_philo->philo_struct->p_nbr > 1)
	{
		pthread_mutex_unlock(&cur_philo->philo_struct->forks
		[cur_philo->left_fork]);
		print_message(cur_philo, "Put down the left fork\n");
		pthread_mutex_unlock(&cur_philo->philo_struct->forks
		[cur_philo->right_fork]);
		print_message(cur_philo, "Put down the right fork\n");
		print_message(cur_philo, "Started sleeping\n");
		usleep(1000 * cur_philo->philo_struct->sleep);
		print_message(cur_philo, "Ended sleeping\n");
	}
}
