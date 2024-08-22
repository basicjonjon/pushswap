/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/22 12:49:36 by jle-doua         ###   ########.fr       */
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
		if (info->lst_b[i] < num && info->lst_b[i] > info->lst_b[target])
		{
			target = i;
		}
		i++;
	}
	return (target);
}

t_cheap	get_cost(t_info *info, int index_num)
{
	int		i;
	int		target_i;
	t_cheap	res;

	i = 0;
	target_i = get_target(info, info->lst_a[index_num]);
	res.index_a = index_num;
	res.index_b = target_i;
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
		if (info->lst_a[i] > num && info->lst_a[i] < info->lst_a[target])
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
	res.index_b = index_num;
	res.score = res.index_a + res.index_b;
	return (res);
}

void	turk_sort(t_info *info)
{
	int		i;
	int		y;
	int		z;
	t_cheap	hit;

	i = 0;
	y = 0;
	z = -1;
	while (i < 2)
	{
		ft_push_b(info);
		i++;
	}
	while (info->lst_a_count != 3)
	{
		i = 0;
		y = 0;
		update_info(info);
		hit = get_cost(info, y);
		while (y < info->lst_a_count)
		{
			y++;
			if (get_cost(info, y).score < hit.score)
				hit = get_cost(info, y);
		}
		i = 0;
		y = 0;
		if (hit.index_a <= info->lst_a_count / 2)
		{
			while (i < hit.index_a)
			{
				ft_rotate_a(info, 'a');
				i++;
			}
		}
		else
		{
			while (i < (info->lst_a_count - hit.index_a))
			{
				ft_rrotate_a(info, 'a');
				i++;
			}
		}
		if (hit.index_b <= info->lst_b_count / 2)
		{
			while (y < hit.index_b)
			{
				ft_rotate_b(info, 'a');
				y++;
			}
		}
		else
		{
			while (y < (info->lst_b_count - hit.index_b))
			{
				ft_rrotate_b(info, 'a');
				y++;
			}
		}
		ft_push_b(info);
	}
	triforce(info);
	while (info->lst_b_count != 0)
	{
		i = 0;
		y = 0;
		update_info(info);
		hit = get_cost_reverse(info, y);
		while (y < info->lst_b_count)
		{
			if (get_cost_reverse(info, y).score < hit.score)
			{
				hit = get_cost_reverse(info, y);
			}
			y++;
		}
		i = 0;
		y = 0;
		if (hit.index_a <= info->lst_a_count / 2)
		{
			while (i < hit.index_a)
			{
				ft_rotate_a(info, 'a');
				i++;
			}
		}
		else
		{
			while (i < (info->lst_a_count - hit.index_a))
			{
				ft_rrotate_a(info, 'a');
				i++;
			}
		}
		if (hit.index_b <= info->lst_b_count / 2)
		{
			while (y < hit.index_b)
			{
				ft_rotate_b(info, 'a');
				y++;
			}
		}
		else
		{
			while (y < (info->lst_b_count - hit.index_b))
			{
				ft_rrotate_b(info, 'a');
				y++;
			}
		}
		ft_push_a(info);
	}
	if (info->a_upper_i != info->lst_a_count - 1)
	{
		i = 0;
		update_info(info);
		if (info->a_upper_i < info->lst_a_count / 2)
		{
			while (i < info->a_upper_i + 1)
			{
				ft_rotate_a(info, 'a');
				i++;
			}
		}
		else
		{
			while (i < info->lst_a_count - 1 - info->a_upper_i)
			{
				ft_rrotate_a(info, 'a');
				i++;
			}
		}
	}
	print_lst(info);
}
