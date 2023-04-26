/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:42:13 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/23 11:17:21 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_error(void)
{
	printf("Error\n");
	exit(1);
}

void ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

bool judge_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
		{
			printf("Error\n");	// ft_printfへ変換
			return (false);
		}
		i++;
	}
	return (true);
}
