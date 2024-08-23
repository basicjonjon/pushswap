/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:51:30 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cheap	get_hit(t_info *info, int mod)
{
	t_cheap	hit;
	int		i;

	i = -1;
	hit.score = 9999999;
	update_info(info);
	if (!mod)
	{
		while (++i < info->lst_a_count)
		{
			if (get_cost(info, i).score < hit.score)
				hit = get_cost(info, i);
		}
	}
	else
	{
		while (++i < info->lst_b_count)
		{
			if (get_cost_reverse(info, i).score < hit.score)
				hit = get_cost_reverse(info, i);
		}
	}
	return (hit);
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
