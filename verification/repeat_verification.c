/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_verification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:45:36 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 15:52:52 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int repeat_verification(t_info *info)
{
	int i;
	int y;
	int value;

	i = 0;
	while (i < info->lst_a_count)
	{
		y = i + 1;
		value = info->lst_a[i];
		while (y < info->lst_a_count)
		{
			if (value == info->lst_a[y])
			{
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}