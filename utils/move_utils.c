/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:03:05 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/24 13:29:56 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_get_next(t_info *info)
{
	int	i;
	int tmp_i;

	if (info->lst_b[0] == info->upper)
		return (2147483649);
	i = 0;
	tmp_i = ft_get_upper_index(info);
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] > info->lst_b[0] && info->lst_a[i] < info->lst_a[tmp_i])
			tmp_i = i;
		i++;
	}
	return (tmp_i);
}

int	ft_get_worth_move(t_info *info)
{
	long preview;
	long next;

	preview = 6;
	next = ft_get_next(info);
	if (next == 2147483649)
		return ((int)preview);
	else if (preview == 2147483649)
		return ((int)next);
	
}