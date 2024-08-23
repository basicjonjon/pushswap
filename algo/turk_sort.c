/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 12:30:32 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	objectif :
	- prendre un nombre n de la liste a;
	- regarder combien de coup (vers le haut ou le bas en fonction de la median) pour le ramener en haut;
	- trouver sa target dans la liste b;
	- regarder combien de coup pour le ramener en haut;
	- push le nombre aui "coute" le moin cher;
*/

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

t_cheap	get_cost(t_info *info, int index_num)
{
	int		target_i;
	t_cheap	res;

	target_i = get_target(info, info->lst_a[index_num]);
	res.a_reverse = 0;
	res.b_reverse = 0;
	res.index_a = index_num;
	if (res.index_a > info->lst_a_count / 2)
	{
		res.index_a = info->lst_a_count - index_num;
		res.a_reverse = 1;
	}
	res.index_b = target_i;
	if (res.index_b > info->lst_b_count / 2)
	{
		res.index_b = info->lst_b_count - target_i;
		res.b_reverse = 1;
	}
	res.score = res.index_a + res.index_b;
	return (res);
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

t_cheap	get_cost_reverse(t_info *info, int index_num)
{
	int		i;
	int		target_i;
	t_cheap	res;

	i = 0;
	target_i = get_target_reverse(info, info->lst_b[index_num]);
	res.index_a = target_i;
	res.a_reverse = 0;
	if (res.index_a > info->lst_a_count / 2)
	{
		res.index_a = info->lst_a_count - res.index_a;
		res.a_reverse = 1;
	}
	res.index_b = index_num;
	res.b_reverse = 0;
	if (res.index_b > info->lst_b_count / 2)
	{
		res.index_b = info->lst_b_count - res.index_b;
		res.b_reverse = 1;
	}
	res.score = res.index_a + res.index_b;
	return (res);
}
t_cheap	get_hit(t_info *info)
{
	t_cheap	hit;
	int		y;

	y = 0;
	hit.score = 9999999;
	update_info(info);
	while (y < info->lst_a_count)
	{
		if (get_cost(info, y).score < hit.score)
			hit = get_cost(info, y);
		y++;
	}
	return (hit);
}

t_cheap	get_hit_reverse(t_info *info)
{
	t_cheap	hit;
	int		y;

	y = 0;
	hit.score = 9999999;
	update_info(info);
	while (y < info->lst_b_count)
	{
		if (get_cost_reverse(info, y).score < hit.score)
		{
			hit = get_cost_reverse(info, y);
		}
		y++;
	}
	return (hit);
}

void	sort_go(t_info *info)
{
	int		i;
	int		y;
	t_cheap	hit;

	i = 0;
	y = 0;
	hit = get_hit(info);
	while (i < hit.index_a)
	{
		if (hit.a_reverse)
			ft_rrotate_a(info, 'a');
		else
			ft_rotate_a(info, 'a');
		i++;
	}
	while (y < hit.index_b)
	{
		if (hit.b_reverse)
			ft_rrotate_b(info, 'a');
		else
			ft_rotate_b(info, 'a');
		y++;
	}
	ft_push_b(info);
}

void	sort_back(t_info *info)
{
	int		i;
	t_cheap	hit;

	i = 0;
	hit = get_hit_reverse(info);
	print_lst(info);
	while (i < hit.index_a)
	{
		if (hit.a_reverse)
			ft_rrotate_a(info, 'a');
		else
			ft_rotate_a(info, 'a');
		i++;
	}
	i = 0;
	while (i < hit.index_b)
	{
		if (hit.b_reverse)
			ft_rrotate_b(info, 'a');
		else
			ft_rotate_b(info, 'a');
		i++;
	}
	ft_push_a(info);
}

void	turk_sort(t_info *info)
{
	int	i;

	i = -1;
	ft_push_b(info);
	ft_push_b(info);
	while (info->lst_a_count != 3)
	{
		sort_go(info);
	}
	triforce(info);
	while (info->lst_b_count != 0)
	{
		sort_back(info);
	}
	// if (info->a_upper_i != info->lst_a_count - 1)
	// {
	// 	i = 0;
	// 	update_info(info);
	// 	if (info->a_upper_i < info->lst_a_count / 2)
	// 	{
	// 		while (i < info->a_upper_i + 1)
	// 		{
	// 			ft_rotate_a(info, 'a');
	// 			i++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (i < info->lst_a_count - 1 - info->a_upper_i)
	// 		{
	// 			ft_rrotate_a(info, 'a');
	// 			i++;
	// 		}
	// 	}
	// }
	print_lst(info);
}
