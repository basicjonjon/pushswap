/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 15:44:11 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	turk_sort(t_info *info)
{
	int	i;

	i = -1;
	ft_push_b(info);
	ft_push_b(info);
	while (info->lst_a_count > 3)
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
