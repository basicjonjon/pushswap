/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:04:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/21 12:20:34 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_verif_finish(t_info *info)
{
	int	i;
	int	temp;

	i = 1;
	temp = info->lst_a[0];
	if (info->lst_a_count < info->argc - 1)
		return (1);
	while (i < info->argc - 1)
	{
		if (temp > info->lst_a[i])
			return (1);
		temp = info->lst_a[i++];
	}
	return (0);
}

// int	ft_get_lower(int *lst, int lst_count)
// {
// 	int	i;
// 	int	lower;

// 	i = 1;
// 	lower = lst[0];
// 	while (i < lst_count)
// 	{
// 		if (lst[i] < lower)
// 			lower = lst[i];
// 		i++;
// 	}
// 	return (lower);
// }



// int	ft_get_upper(int *lst, int lst_count)
// {
// 	int	i;
// 	int	upper;

// 	i = 0;
// 	upper = lst[0];
// 	while (i < lst_count)
// 	{
// 		if (lst[i] > upper)
// 			upper = lst[i];
// 		i++;
// 	}
// 	return (upper);
// }

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
		if (lst[i] > lst[upper])
			upper = i;
		i++;
	}
	return (upper);
}
