/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:04:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/15 19:00:10 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verif_finish(int *lst_a, int argc, int count_a)
{
	int	i;
	int	temp;

	i = 1;
	temp = lst_a[0];
	if (count_a < argc - 1)
		return (0);
	while (i < argc - 1)
	{
		if (temp > lst_a[i])
			return (1);
		temp = lst_a[i++];
	}
	return (0);
}


int	ft_get_lower(int *lst_a, int lst_a_count)
{
	int	i;
	int	lower;

	i = 1;
	lower = lst_a[0];
	while (i < lst_a_count)
	{
		if (lst_a[i] < lower)
			lower = lst_a[i];
		i++;
	}
	return (lower);
}

int	ft_get_lower_index(int *lst_a, int lst_a_count)
{
	int	i;
	int	lower;

	i = 1;
	lower = 0;
	while (i < lst_a_count)
	{
		if (lst_a[i] < lst_a[lower])
			lower = i;
		i++;
	}
	return (lower);
}

int	ft_get_upper(int *lst_a, int lst_a_count)
{
	int	i;
	int	upper;

	i = 1;
	upper = lst_a[0];
	while (i < lst_a_count)
	{
		if (lst_a[i] > upper)
			upper = lst_a[i];
		i++;
	}
	return (upper);
}

int	ft_get_upper_index(int *lst_a, int lst_a_count)
{
	int	i;
	int	upper;

	i = 1;
	upper = 0;
	while (i < lst_a_count)
	{
		if (lst_a[i] > lst_a[upper])
			upper = i;
		i++;
	}
	return (upper);
}