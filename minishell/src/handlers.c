/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:59:14 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:32:26 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	child_sig_handler_bash(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		exit(0);
	}
}

void	child_sig_handler(int sig)
{
	if (sig == SIGINT)
		write(2, "\n", 1);
}

void	sig_handler(int sig)
{	
	if (sig == SIGINT)
	{	
		rl_on_new_line();
		rl_redisplay();
		write(2, "  ", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_replace_line("", 0);
		write(2, "\n", 1);
		rl_redisplay();
	}
}
