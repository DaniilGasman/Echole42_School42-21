/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:29:35 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:40:08 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

t_list	*ft_take_last_arg(t_list *alst, int type)
{
	t_list	*ptr;

	if (alst == NULL)
		return (NULL);
	ptr = alst;
	while (ptr != NULL)
	{
		if (ptr->type == type)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_list	*ft_lstnew(int type, void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_add_lst_back(t_list **alst, t_list *new)
{
	t_list	*first;

	if (new == NULL || alst == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		first = *alst;
		while (first->next != NULL)
			first = first->next;
		first->next = new;
		new->next = NULL;
	}
}
