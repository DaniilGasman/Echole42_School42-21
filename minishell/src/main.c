/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:05:47 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 23:52:45 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_num_size(int n, int sign)
{
	int	digits;

	digits = 1;
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	if (sign > 0)
		return (digits);
	else
		return (digits + 1);
}

void	ft_init_param(t_data **prm, char **argv, char **env, int *ret)
{
	(*prm) = (t_data *)malloc(sizeof(t_data));
	(*prm)->env = env_cpy(env, 0);
	(*prm)->export = (char **)ft_calloc(sizeof(char *), 1);
	(*prm)->argv = argv;
	(*prm)->ret = 0;
	(*prm)->str = 0;
	(*prm)->child = 0;
	ret[0] = 1;
}

void	ft_print_autors(void)
{
	printf("\033[1;31m");
	printf("█──█─███─███─████──████─██─██─█──█─███\n");
	printf("██─█─█───█───█──██─█──█──███──█─█───█\n");
	printf("█─██─███─███─█──██─████───█───██────█\n");
	printf("█──█─█───█───█──██─█──█───█───█─█───█\n");
	printf("█──█─█───███─████──█──█───█───█──█─███\n");
	printf("──────────────────────────█\n");
	printf("\033[1;33m");
	printf("──────────────────────────────────────\n");
	printf("────────████──█──█──████\n");
	printf("────────█──█──██─█──█──██\n");
	printf("────────████──█─██──█──██\n");
	printf("────────█──█──█──█──█──██\n");
	printf("────────█──█──█──█──████\n");
	printf("──────────────────────────────────────\n");
	printf("\033[1;32m");
	printf("████───█───██─███──█──█──███──████──█─█──████\n");
	printf("█──██──██─███──█───██─█──█────█──█──█─█──█──█\n");
	printf("█──██──█─█─██──█───█─██──███──████──█─█──████\n");
	printf("█──██──█───██──█───█──█──█────█─█───███──█──█\n");
	printf("████───█───██─███──█──█──███──█─█────█───█──█\n\n");
}

int	main(int argc, char **argv, char **env)
{
	t_data	*prm;
	int		ret[2];

	if (argc != 1)
		return (1);
	ft_init_param(&prm, argv, env, ret);
	signal(SIGQUIT, SIG_IGN);
	ft_print_autors();
	while (1)
	{	
		signal(SIGINT, sig_handler);
		prm->str = readline("\033[1;35mminishell :\033[0;0m");
		if (prm->str == NULL)
		{
			printf("\033[A");
			printf("\033[1;35mminishell :\033[0;0mexit\n");
			exit(0);
		}
		add_history(prm->str);
		ret[1] = (int)ft_strlen(prm->str);
		parser(prm);
	}
	return (0);
}
