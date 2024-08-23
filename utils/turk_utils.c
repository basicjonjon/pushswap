/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:18:10 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:20:04 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_info(t_info *info)
{
	info->a_upper_i = ft_get_upper_i(info->lst_a, info->lst_a_count);
	info->a_lower_i = ft_get_lower_i(info->lst_a, info->lst_a_count);
	info->b_upper_i = ft_get_upper_i(info->lst_b, info->lst_b_count);
	info->b_lower_i = ft_get_lower_i(info->lst_b, info->lst_b_count);
}

int	get_target(t_info *info, int num)
{
	int	i;
	int	target;

	i = 0;
	target = info->b_lower_i;
	if (num < info->lst_b[target] || num > info->lst_b[info->b_upper_i])
		return (info->b_upper_i);
	while (i < info->lst_b_count)
	{
		if (info->lst_b[i] <= num && info->lst_b[i] > info->lst_b[target])
			target = i;
		i++;
	}
	return (target);
}

int	get_target_reverse(t_info *info, int num)
{
	int	i;
	int	target;

	i = 0;
	target = info->a_upper_i;
	if (num > info->lst_a[target] || num < info->lst_a[info->a_lower_i])
		return (info->a_lower_i);
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] >= num && info->lst_a[i] < info->lst_a[target])
		{
			target = i;
		}
		i++;
	}
	return (target);
}

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
	t_cheap	res;

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
