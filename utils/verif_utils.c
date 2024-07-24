/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:04:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/24 13:19:35 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verif_finish(t_info *info)
{
	int	i;
	int	temp;

	i = 1;
	temp = info->lst_a[0];
	if (info->lst_a_count < info->argc - 1)
		return (0);
	while (i < info->argc - 1)
	{
		if (temp > info->lst_a[i])
			return (1);
		temp = info->lst_a[i++];
	}
	return (0);
}

int	ft_get_lower(t_info *info)
{
	int	i;
	int	lower;

	i = 1;
	lower = info->lst_a[0];
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] < lower)
			lower = info->lst_a[i];
		i++;
	}
	return (lower);
}

int	ft_get_lower_index(t_info *info)
{
	int	i;
	int	lower;

	i = 1;
	lower = 0;
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] < info->lst_a[lower])
			lower = i;
		i++;
	}
	return (lower);
}

int	ft_get_upper(t_info *info)
{
	int	i;
	int	upper;

	i = 1;
	upper = info->lst_a[0];
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] > upper)
			upper = info->lst_a[i];
		i++;
	}
	return (upper);
}

int	ft_get_upper_index(t_info *info)
{
	int	i;
	int	upper;

	i = 1;
	upper = 0;
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] > info->lst_a[upper])
			upper = i;
		i++;
	}
	return (upper);
}