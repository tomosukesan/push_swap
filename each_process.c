/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   each_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:57:30 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 07:18:57 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	each_process(t_list **a_stack, size_t elements, t_cmd_lst **commands)
{
	t_list	*b_stack;

	b_stack = NULL;		// b_stackはelements >= 4のときに必要となる
	if (elements == 2)
		if (((*a_stack)->next)->rank != 1)
			swap(a_stack, commands, ft_strdup("sa\n")); // saしてみよう
	//else if (elements == 3)
	//	process_three_elements();

	(void) b_stack;
}
