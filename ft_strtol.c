/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:15:15 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/23 14:00:37 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_isspace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static char	judge_sign(char sign)
{
	if (sign == '-')
		sign = -1;
	else if (sign == '+')
		sign = 1;
	return (sign);
}

static long	check_intmin(char *str, size_t i, long result)
{
	if (result == INT_MIN && str[++i] == '\0')
		return (INT_MIN);
	return (FALSE);
}

long	ft_strtol(char *str)
{
	size_t	i;
	char	sign;
	long	result;

	i = ft_isspace(str);
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = judge_sign(str[i]);
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (check_intmin(str, i, result * (long)sign));
		i++;
	}
	if (str[i] != '\0')
		return (FALSE);
	return (result * sign);
}
