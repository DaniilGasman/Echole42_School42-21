/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:02:26 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/30 18:47:16 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_philo(t_philo *philo)
{
	int	i;

	i = -1;
	philo->list = (t_plist *)malloc(sizeof(t_plist) * philo->p_nbr);
	while (philo->p_nbr > i++)
	{
		philo->list[i].eating = 0;
		philo->list[i].ate = 0;
		philo->list[i].p_pos = i;
		philo->list[i].left_fork = i;
		philo->list[i].right_fork = (i + 1) % philo->p_nbr;
		philo->list[i].philo_struct = philo;
	}
	if (philo->p_nbr == 1)
		philo->list[0].right_fork = -1;
}

void	eat(t_plist *cur_philo)
{
	if (cur_philo->philo_struct->p_nbr > 1)
	{
		cur_philo->eating = 1;
		cur_philo->last_eat = ft_time();
		cur_philo->ate++;
		if (cur_philo->ate == cur_philo->philo_struct->must_eat_flag)
			cur_philo->philo_struct->total_eat++;
		print_message(cur_philo, "\033[1;32m is eating \033[0;0m\n");
		usleep(1000 * cur_philo->philo_struct->eat);
		cur_philo->eating = 0;
	}
}

int	lets_go(t_philo *philo)
{
	pthread_t	thread;
	void		*philos;
	int			i;

	i = 0;
	if (!fork_creator(philo))
		return (0);
	init_philo(philo);
	philos = (void *)philo;
	if (philo->must_eat_flag != -1)
	{
		if (pthread_create(&thread, NULL, &must_eat, philos) != 0)
			return (0);
		pthread_detach(thread);
	}
	while (i < philo->p_nbr)
	{
		if (pthread_create(&philo->list[i].self_th, NULL, &ft_live,
				(void *)(&philo->list[i])) != 0)
			return (0);
		pthread_detach(philo->list[i].self_th);
		usleep(10);
		i++;
	}
	return (1);
}
