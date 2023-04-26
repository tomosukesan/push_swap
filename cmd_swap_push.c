/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:30:41 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 15:37:09 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, t_cmd_lst **commands, char *cmd)
{
	t_list	*first;
	t_list	*second;

	first = (*stack)->next;
	second = first->next;
	(*stack)->next = second;
	first->next = second->next;
	first->prev = second;
	second->prev = *stack;
	second->next = first;
	ft_strlst_addback(commands, ft_strlst_new(cmd));
}

void	both_swap(t_list **a_stack, t_list **b_stack, t_cmd_lst **commands)
{
	t_list	*first;
	t_list	*second;

	first = (*b_stack)->next;
	second = first->next;
	(*b_stack)->next = second;
	first->next = second->next;
	first->prev = second;
	second->prev = *b_stack;
	second->next = first;
	swap(a_stack, commands, ft_strdup("ss\n"));
}

void	push(t_list **dst, t_list **src, t_cmd_lst **commands, char *cmd)
{
	t_list	*src_head;
	t_list	*dst_head;

	if (src == NULL)
		return ;
	src_head = (*src)->next;
	dst_head = (*dst)->next;
	(*src)->next = src_head->next;
	(src_head->next)->prev = *src;
	(*dst)->next = src_head;
	src_head->next = dst_head;
	dst_head->prev = src_head;
	src_head->prev = *dst;
}
