/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_listed_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:34:19 by ttachi            #+#    #+#             */
/*   Updated: 2023/04/23 08:43:35 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 要素数を返す
 * 数値の重複があればErrorとなる
 * そのときは０をかえそう
 * listのrankを1から付与していく
 * 例： 69870  6789  879  6578  546  2345  13245
 * 7つの数値があったとき...どうやってrankingしているか
 * 番兵nodeのrankは-1とする. 座標圧縮は未rankづけの状態を0. rankingは1をスタートとする

*/

/**
while (target->rank != -1) // 1周する
{

}
*/

unsigned int	check_listed_num(t_list **data)
{
	unsigned int	elements;
	unsigned int	i;
	t_list			*next_node;
	t_list			*target;

	i = 0;
	elements = ((*data)->prev)->rank + 1;
	next_node = (*data)->next;
	while (i < elements)
	{
		/**
		 * 1からどんどんランキング
		 * 全部のnodeを見る
		 * でも書き換えるのはrank == 0のときだけ
		 * (*data)->num
		*/


	}
	while (target->rank != -1)
	{
		target = next_node;
		next_node = target->next;
		//
	}
	return (elements);
}
