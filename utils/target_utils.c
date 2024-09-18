/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:18:10 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/09 15:54:41 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_lower_i(int *lst, int lst_count)
{
	int	i;
	int	lower;

	i = 1;
	lower = 0;
	while (i < lst_count)
	{
		if (lst[i] < lst[lower])
			lower = i;
		i++;
	}
	return (lower);
}

int	ft_get_upper_i(int *lst, int lst_count)
{
	int	i;
	int	upper;

	i = 0;
	upper = 0;
	while (i < lst_count)
	{
		if (lst[i] >= lst[upper])
			upper = i;
		i++;
	}
	return (upper);
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
