/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:26:43 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/25 14:00:30 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	 * strsを数値配列に変換
	 * ここでは数値でなかったらErrorの処理を
	 * それをソートして、その要素数がrankとなる
	 * 座標圧縮の一般的なやり方は配列をコピー、ソート、
*/

static bool	store_num(t_list **lst, size_t elements, char **strs, int *arr)
{
	size_t	i;
	long	num;
	t_list	*new_node;

	i = 0;
	while (i < elements)
	{
		num = ft_strtol(strs[i]);
		if (num == FALSE)
		{
			ft_numlst_clear(lst);
			return (false);
		}
		arr[i] = (int)num;	// rankはi+1となることに注意
		new_node = ft_numlst_new((int)num, 0);
		if (new_node == NULL)
		{
			ft_numlst_clear(lst);
			return (false);
		}
		ft_numlst_addback(lst, new_node);
		i++;
	}
	return (true);
}

static t_list *free_and_return(int *array)
{
	free(array);
	return (NULL);
}

static bool	sort_array(int *array, size_t elements)
{
	int		temp;
	size_t	i;

	while (elements > 1)
	{
		i = 0;
		while (i < elements - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			else if (array[i] == array[i + 1])
				return (false);
			i++;
		}
		elements--;
	}
	return (true);
}

static void	set_rank(t_list **lst, size_t elements, int *sorted)
{
	t_list	*target;
	size_t	min;
	size_t	max;
	size_t	mid;

	target = (*lst)->next;
	while (target->rank != -1)
	{
		min = 0;
		max = elements - 1;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (target->num < sorted[mid])
				max = mid - 1;
			else if (target->num > sorted[mid])
				min = mid + 1;
			else
				break ;
		}
		target->rank = mid + 1;
		target = target->next;
	}
}

t_list	*conv_num_list(size_t elements, char **strs)
{
	t_list	*num_list;
	int		*to_sort;
	bool	num_check_str;
	bool	num_check_same;

	num_list = ft_numlst_new(0, -1);
	if (num_list == NULL)
		return (NULL);
	to_sort = malloc(sizeof(int) * elements);
	num_check_str = store_num(&num_list, elements, strs, to_sort);
	if (num_check_str == false)
		return (free_and_return(to_sort));
	num_check_same = sort_array(to_sort, elements);
	if (num_check_same == false)
		return (free_and_return(to_sort));
	set_rank(&num_list, elements, to_sort);
	free(to_sort);
	return (num_list);
}
