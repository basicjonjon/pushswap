/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:08:33 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 12:09:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cheap	get_cost(t_info *info, int index_num)
{
	t_cheap	res;

	res.index_a = index_num;
	res.index_b = get_target(info, info->lst_a[index_num]);
	res.a_reverse = 0;
	res.b_reverse = 0;
	if (res.index_a > info->lst_a_count / 2)
	{
		res.index_a = info->lst_a_count - res.index_a;
		res.a_reverse = 1;
	}
	if (res.index_b > info->lst_b_count / 2)
	{
		res.index_b = info->lst_b_count - res.index_b;
		res.b_reverse = 1;
	}
	res.score = res.index_a + res.index_b;
	return (res);
}

t_cheap	get_cost_reverse(t_info *info, int index_num)
{
	t_cheap res;

	res.index_a = get_target_reverse(info, info->lst_b[index_num]);
	res.index_b = index_num;
	res.a_reverse = 0;
	res.b_reverse = 0;
	if (res.index_a > info->lst_a_count / 2)
	{
		res.index_a = info->lst_a_count - res.index_a;
		res.a_reverse = 1;
	}
	if (res.index_b > info->lst_b_count / 2)
	{
		res.index_b = info->lst_b_count - res.index_b;
		res.b_reverse = 1;
	}
	res.score = res.index_a + res.index_b;
	return (res);
}
