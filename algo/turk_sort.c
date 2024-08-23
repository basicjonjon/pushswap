/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 14:01:17 by jle-doua         ###   ########.fr       */
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

t_cheap	get_hit(t_info *info, int mod)
{
	t_cheap	hit;
	int		i;

	i = -1;
	hit.score = 9999999;
	update_info(info);
	if (!mod)
		while (++i < info->lst_a_count)
		{
			if (get_cost(info, i).score < hit.score)
				hit = get_cost(info, i);
		}
	else
		while (++i < info->lst_b_count)
		{
			if (get_cost_reverse(info, i).score < hit.score)
				hit = get_cost_reverse(info, i);
		}
	return (hit);
}

void	move_list(t_info *info, int mod)
{
	int		i;
	t_cheap	hit;

	i = -1;
	hit = get_hit(info, mod);
	while (++i < hit.index_a)
	{
		if (hit.a_reverse)
			ft_rrotate_a(info, 'a');
		else
			ft_rotate_a(info, 'a');
	}
	i = -1;
	while (++i < hit.index_b)
	{
		if (hit.b_reverse)
			ft_rrotate_b(info, 'a');
		else
			ft_rotate_b(info, 'a');
	}
}

void	turk_sort(t_info *info)
{
	int	i;

	i = -1;
	ft_push_b(info);
	ft_push_b(info);
	while (info->lst_a_count != 3)
	{
		move_list(info, 0);
		ft_push_b(info);
	}
	triforce(info);
	while (info->lst_b_count != 0)
	{
		move_list(info, 1);
		ft_push_a(info);
	}
	update_info(info);
	while (info->a_lower_i != 0)
	{
		if (info->a_lower_i <= info->lst_a_count / 2)
			ft_rotate_a(info, 'a');
		else
			ft_rrotate_a(info, 'a');
		update_info(info);
	}
}
