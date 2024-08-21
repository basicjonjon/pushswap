/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:04:41 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/21 12:12:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	ft_get_next_i(t_info *info)
{
	int	i;
	int	upper;

	if (info->lst_b[0] >=  info->lst_a[info->a_upper_i])
		return (ft_get_lower_i(info->lst_a, info->lst_a_count));
	i = 0;
	upper = ft_get_upper_i(info->lst_a, info->lst_a_count);
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] > info->lst_b[0]
			&& info->lst_a[i] < info->lst_a[upper])
			upper = i;
		i++;
	}
	return (upper);
}

void	five_num(t_info *info)
{
	int	i;

	i = -1;
	while (info->lst_a_count != 3)
		ft_push_b(info);
	triforce(info);
	while (info->lst_b_count != 0)
	{
		while (info->lst_a[0] != info->lst_a[ft_get_next_i(info)])
		{
			if (ft_get_next_i(info) < info->lst_a_count / 2)
				ft_rotate_a(info, 'a');
			else
				ft_rrotate_a(info, 'a');
		}
		ft_push_a(info);
	}
	if (ft_get_upper_i(info->lst_a, info->lst_a_count) < info->lst_a_count / 2)
		while (ft_verif_finish(info))
			ft_rotate_a(info, 'a');
	else
		while (ft_verif_finish(info))
			ft_rrotate_a(info, 'a');
}
