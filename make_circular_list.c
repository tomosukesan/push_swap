/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circular_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:23:39 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/24 18:42:12 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	cnt_elements(char *argv[], bool argv_flag)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	if (i >= argv_flag)
		i = i - argv_flag;
	return (i);
}

static char	**check_argv(char *argv[], size_t *elements, bool *split_flag)
{
	char	**strs;
	size_t	split_elements;

	strs = NULL;
	split_elements = 0;
	strs = ft_split(argv[1], ' ');
	if (strs == NULL)
		ft_error();
	else if (strs[0] == NULL)
	{
		ft_free(strs);
		ft_error();
	}
	*split_flag = true;
	split_elements = cnt_elements(strs, false);
	if (split_elements == 1)
	{
		judge_num(strs[0]);
		ft_free(strs);
		exit(0);
	}
	*elements = split_elements;
	return (strs);
}

t_list	*make_circular_list(char *argv[], size_t *elements)
{
	bool	split_flag;
	char	**strs;
	t_list	*circular_list;

	*elements = cnt_elements(argv, true);
	split_flag = false;
	if (*elements < 1)
		exit(0);
	else if (*elements == 1)
		strs = check_argv(argv, elements, &split_flag);
	else
		strs = ++argv;
	circular_list = conv_num_list(*elements, strs);
	if (circular_list == NULL)
	{
		if (split_flag == true)
			ft_free(strs);
		ft_error();
	}
	return (circular_list);
}
