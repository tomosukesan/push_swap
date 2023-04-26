/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:44:35 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/26 14:14:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void	push(t_list **dst, t_list **src, t_cmd_lst **commands, char *cmd)
{
	t_list	*src_head;
	t_list	*dst_head;

	if (src == NULL)
		return ;
	src_head = (*src)->next;
	dst_head = (*dst)->next;

	// srcとdstそれぞれ、前後のnodeの処理が必要
	// 前にあったものはnextが変更となり、後ろにあったものはprevが変更
	// src_head自体はprevがdstとなり、nextはdst_headとなる？
	(*src)->next = src_head.next;
	(src_head->next)->prev = *src;
	(*dst)->next = src_head;
	(dst_head->next)->prev = src_head;
	dst_head->prev = *dst;
	dst_head->next = (dst_head->next)->next;
}
