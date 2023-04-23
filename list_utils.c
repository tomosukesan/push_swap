/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:29:59 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/21 21:11:42 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num, int rank)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->rank = rank;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst)->prev == NULL && (*lst)->next == NULL)
	{
		(*lst)->prev = new;
		(*lst)->next = new;
		new->prev = *lst;
		new->next = *lst;
	}
	else
	{
		new->prev = (*lst)->prev;
		((*lst)->prev)->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
}

t_list	*ft_lstclear(t_list **lst)
{
	t_list	*next_node;
	t_list	*target;

	if (lst == NULL)
		return (NULL);
	next_node = (*lst)->next;
	while (next_node->rank != -1)
	{
		target = next_node;
		next_node = target->next;
		free(target);
	}
	free(*lst);
	return (NULL);
}
