/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:10:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 13:50:59 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cheap	get_hit(t_info *info, int mod)
{
	int 	i;
	t_cheap hit;

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