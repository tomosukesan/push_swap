/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:39:56 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 07:22:31 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_cmd(t_cmd_lst *commands)
{
	t_cmd_lst	*target;

	target = commands;
	while (target != NULL)
	{
		printf("%s", target->content);
		target = target->next;
	}
}

int	push_swap(char *argv[])
{
	t_list		*a_stack;
	size_t		elements;
	t_cmd_lst	*commands;

	elements = 0;
	commands = NULL;
	a_stack = make_circular_list(argv, &elements);
	execute_cmd(&a_stack, elements, &commands);
	// elements == 2のときはちゃんとswapされた
	// elements >= 3のときにどうしていけばよいかは、校舎で聞きながらやってみよう！いまは各コマンドを実装する
	print_cmd(commands);
	ft_strlst_clear(&commands);
	//
	print_listnum(a_stack);
	ft_numlst_clear(&a_stack);
	//
	return (0);
}
