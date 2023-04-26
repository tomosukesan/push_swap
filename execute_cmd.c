/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:59:47 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/25 14:23:59 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_list **a_stack, size_t elements, t_cmd_lst **commands)
{
	if (elements < 7)
		each_process(a_stack, elements, commands);
	else
	{
		// b_stackはこの先で作成
	}
	// a_stackがsortされている確認を。
}
