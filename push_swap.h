/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:41:46 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 15:44:12 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

# define FALSE LONG_MAX

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				num;
	int				rank;
}	t_list;

typedef struct s_cmd_lst
{
	struct s_cmd_lst	*next;
	char				*content;
}	t_cmd_lst;

int			push_swap(char *argv[]);
t_list		*make_circular_list(char *argv[], size_t *elements);
t_list		*conv_num_list(size_t elements, char **strs);
void		ft_free(char **array);
void		ft_error(void);
bool 		judge_num(char *str);
long		ft_strtol(char *str);
t_list		*ft_numlst_new(int num, int rank);
t_list		*ft_numlst_last(t_list *lst);
void		ft_numlst_addback(t_list **lst, t_list *new);
t_list		*ft_numlst_clear(t_list **lst);
t_cmd_lst	*ft_strlst_new(char *cmd);
t_cmd_lst	*ft_strlst_last(t_cmd_lst *lst);
void		ft_strlst_addback(t_cmd_lst **lst, t_cmd_lst *new);
void		ft_strlst_clear(t_cmd_lst **lst);
void		execute_cmd(t_list **a_stack, size_t elements, t_cmd_lst **commands);
void		each_process(t_list **a_stack, size_t elements, t_cmd_lst **commands);
void		swap(t_list **stack, t_cmd_lst **commands, char *cmd);
void		both_swap(t_list **a_stack, t_list b_stack, t_cmd_lst **commands);
void		push(t_list **dst, t_list **src, t_cmd_lst **commands, char *cmd);
void		rotate(t_list **stack, t_cmd_lst **commands, char *cmd);
void		both_rotate(t_list **a_stk, t_list **b_stk, t_cmd_lst **cmd);
void		both_reverse_rotate(t_list **a_stk, t_list **b_stk, t_cmd_lst **cmd);



//size_t	check_listed_num(t_list **data);


void	print_listnum(t_list *lst);
//int	test_push_swap(char *argv[]);

#endif
