/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undred_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:42:39 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/18 17:52:51 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_low_number(int *lst, int start, int nb, t_info *info)
{
	int	i;
	int	index;

	i = start;
	index = ft_get_lower_i(lst,info->lst_a_count);
	while (i < info->lst_a_count)
	{
		if (lst[i] < nb && lst[i] > lst[index])
		{
			index = i;
		}
		i++;
	}
	return (index);
}

void	undred_num(t_info *info)
{
	ft_push_b(info);
	int lower = get_low_number(info->lst_a,0,info->lst_b[0], info);
	printf("%s LOWER %i%s NUM = %i\n", GREEN, lower, NC, info->lst_a[lower]);
}