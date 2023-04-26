/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:19:11 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 19:22:36 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, t_cmd_lst **commands, char *cmd)
{
	t_list	*head;
	t_list	*tail;

	head = (*stack)->next;
	tail = (*stack)->prev;
	(*stack)->next = head->next;
	(head->next)->prev = *stack;
	(*stack)->prev = head;
	head->next = *stack;
	head->prev = tail;
	tail->next = head;
	ft_strlst_addback(commands, ft_strlst_new(cmd));
}

void	both_rotate(t_list **a_stk, t_list **b_stk, t_cmd_lst **cmd)
{
	t_list	*head;
	t_list	*tail;

	head = (*b_stk)->next;
	tail = (*b_stk)->prev;
	(*b_stk)->next = head->next;
	(head->next)->prev = *b_stk;
	(*b_stk)->prev = head;
	head->next = *b_stk;
	head->prev = tail;
	tail->next = head;
	rotate(a_stk, cmd, ft_strdup("ss\n"));
}

void	reverse_rotate(t_list **stack, t_cmd_lst **commands, char *cmd)
{
	t_list	*head;
	t_list	*tail;

	head = (*stack)->next;
	tail = (*stack)->prev;
	tail->prev = *stack;
	// in the middle
}

