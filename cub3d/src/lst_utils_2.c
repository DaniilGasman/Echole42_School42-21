/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:29:27 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/12 19:49:45 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

void	ft_lst_del_one(t_list **lst, t_list *one)
{
	t_list	*ptr;

	if (lst == NULL || one == NULL)
		return ;
	if (*lst == one)
	{
		*lst = (*lst)->next;
		ft_lst_clear_content(one);
		one = NULL;
	}
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
		{
			if (ptr->next == one)
			{
				ptr->next = one->next;
				ft_lst_clear_content(one);
				one = NULL;
			}
			else
				ptr = ptr->next;
		}
	}
}

void	ft_lst_clear_content(t_list *lst)
{
	t_map	*ptr;
	int		i;

	if (lst->type == ID_MAP)
	{
		ptr = (t_map *)(lst->content);
		i = 0;
		while (ptr->grid[i])
		{
			free(ptr->grid[i]);
			ptr->grid[i] = NULL;
			i++;
		}
		free(ptr->grid);
		ptr->grid = NULL;
	}
	free(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_dlist_clear(t_list **lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		ft_lst_clear_content(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
