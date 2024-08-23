/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triforce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:30:01 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:16:10 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verif_triforce(t_info *info)
{
	int	i;
	int	value;

	i = 1;
	value = info->lst_a[0];
	while (i < info->lst_a_count)
	{
		if (value > info->lst_a[i])
			return (0);
		i++;
	}
	return (1);
}

void	triforce(t_info *info)
{
	int	upper_i;

	if (verif_triforce(info))
		return ;
	update_info(info);
	upper_i = ft_get_upper_i(info->lst_a, info->lst_a_count);
	if (info->lst_a[info->lst_a_count - 1] != info->lst_a[upper_i])
	{
		if (upper_i < info->lst_a_count / 2)
		{
			ft_rotate_a(info, 'a');
		}
		else
		{
			ft_rrotate_a(info, 'a');
		}
	}
	if (info->lst_a[0] > info->lst_a[1])
		ft_swap_a(info, 'a');
}
