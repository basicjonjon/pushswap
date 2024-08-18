/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triforce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:30:01 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/18 15:08:40 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	triforce(t_info *info)
{
	int	lower_i;

	lower_i = ft_get_upper_i(info->lst_a, info->lst_a_count);
	if (info->lst_a[info->argc - 1] != info->upper)
	{
		if (lower_i < info->lst_a_count / 2)
			ft_rotate_a(info, 'a');
		else
			ft_rrotate_a(info, 'a');
	}
	if (info->lst_a[0] > info->lst_a[1])
		ft_swap_a(info, 'a');
}
