/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:26:43 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/23 10:53:15 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	 * strsを数値配列に変換
	 * それをソートして、その要素数がrankとなる
	 * 座標圧縮の一般的なやり方は配列をコピー、ソート、
*/

t_list	*conv_num_list(unsigned int elements, char **strs)
{
	unsigned int	i;
	long			num;
	t_list			*num_list;
	t_list			*new_node;

	i = 0;
	num_list = ft_lstnew(0, -1);
	if (num_list == NULL)
		return (NULL);
	while (i < elements)
	{
		num = ft_strtol(strs[i]);
		if (num == FALSE)
		{
			printf("Error\n");
			return (ft_lstclear(&num_list));
		}
		i++;
		new_node = ft_lstnew((int)num, 0);
		if (new_node == NULL)
			return (ft_lstclear(&num_list));
		ft_lstadd_back(&num_list, new_node);
	}
	return (num_list);
}
