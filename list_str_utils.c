/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_str_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:54:25 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 07:21:57 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd_lst	*ft_strlst_new(char *command)
{
	t_cmd_lst	*node;

	node = malloc(sizeof(t_cmd_lst));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->content = command;
	return (node);
}

t_cmd_lst	*ft_strlst_last(t_cmd_lst *lst)
{
	t_cmd_lst	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_strlst_addback(t_cmd_lst **lst, t_cmd_lst *new)
{
	t_cmd_lst	*tail;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tail = ft_strlst_last(*lst);
		tail->next = new;
	}
}

void	ft_strlst_clear(t_cmd_lst **lst)
{
	t_cmd_lst	*next_node;

	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
}
