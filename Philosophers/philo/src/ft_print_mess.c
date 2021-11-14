/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:20:25 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/27 14:38:36 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_message(t_plist *cur_philo, char *str)
{
	int	cp;

	pthread_mutex_lock(&cur_philo->philo_struct->message);
	if (cur_philo->philo_struct->dead_flag == 0
		&& cur_philo->philo_struct->must_eat_search == 0)
	{
		printf("%s%llu%s", "\033[1;33m", ft_time()
			- cur_philo->philo_struct->start_time, "\033[0;0m");
		cp = cur_philo->p_pos + 1;
		printf(" %d", cp);
		printf(" %s\n", str);
	}
	pthread_mutex_unlock(&cur_philo->philo_struct->message);
}
