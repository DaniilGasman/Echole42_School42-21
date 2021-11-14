/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:40:24 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/30 16:51:31 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->p_nbr + 1)
	{
		pthread_mutex_destroy(&(philo->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(philo->message));
	pthread_mutex_destroy(&(philo->check_dead));
	free(philo->list);
	free(philo);
}
