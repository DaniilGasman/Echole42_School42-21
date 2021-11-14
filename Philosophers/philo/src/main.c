/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:13:10 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/30 18:54:02 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_autor(void)
{
	printf("\033[1;31m");
	printf("█──█─███─███─████──████─██─██─█──█─███\n");
	printf("██─█─█───█───█──██─█──█──███──█─█───█\n");
	printf("█─██─███─███─█──██─████───█───██────█\n");
	printf("█──█─█───█───█──██─█──█───█───█─█───█\n");
	printf("█──█─█───███─████──█──█───█───█──█─███\n");
	printf("──────────────────────────█\n\n");
	printf("\033[0;0m");
}

int	check_params(int __unused argc, char **argv, t_philo *philo)
{
	philo->p_nbr = ft_atoi(argv[1]);
	if (philo->p_nbr <= 0)
		philo->err_msg = ft_strdup("We need more philosophers!\n");
	philo->p_d = ft_atoi(argv[2]);
	if (philo->p_d <= 0)
		philo->err_msg = ft_strdup("You entered the wrong time of death\n");
	philo->p_e = ft_atoi(argv[3]);
	if (philo->p_e <= 0)
		philo->err_msg = ft_strdup("You entered the wrong meal time\n");
	philo->p_s = ft_atoi(argv[4]);
	if (philo->p_s <= 0)
		philo->err_msg = ft_strdup("You entered the wrong sleep time\n");
	if (argv[5])
	{
		philo->must_eat_flag = ft_atoi(argv[5]);
		if (philo->must_eat_flag <= 0)
			philo->err_msg = ft_strdup("Wrong times to eat\n");
	}
	if (philo->err_msg)
		return (1);
	return (0);
}

void	ft_kostil(int __unused argc, char **argv, t_philo *philo)
{
	philo->p_nbr = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	ft_print_autor();
	if (ft_philo_init(&philo) == 1)
		write(1, "Malloc error\n", 13);
	if (argc != 5 & argc != 6)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (0);
	}
	ft_kostil(argc, argv, philo);
	if (check_params(argc, argv, philo))
	{
		printf("%s", philo->err_msg);
		return (0);
	}
	if (!lets_go(philo))
	{
		write(1, "Something is wrong senpai\n", 26);
		return (0);
	}
	pthread_mutex_lock(&(philo->check_dead));
	pthread_mutex_unlock(&(philo->check_dead));
	free_mutex(philo);
	return (0);
}
