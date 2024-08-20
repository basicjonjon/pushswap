/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:19:21 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/20 17:12:04 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_push_a(t_info *info)
{
	int	tmp_value;

	if (info->lst_b_count <= 0)
		return (-1);
	tmp_value = info->lst_b[0];
	info->lst_a_count++;
	ft_down_lst(info->lst_a, info->lst_a_count);
	info->lst_a[0] = tmp_value;
	ft_up_lst(info->lst_b, info->lst_b_count);
	info->lst_b_count -= 1;
	ft_printf("pa\n");
	info->action_count++;
	return (1);
}

int	ft_push_b(t_info *info)
{
	int	tmp_value;

	if (info->lst_a_count <= 0)
		return (-1);
	tmp_value = info->lst_a[0];
	info->lst_b_count++;
	ft_down_lst(info->lst_b, info->lst_b_count);
	info->lst_b[0] = tmp_value;
	ft_up_lst(info->lst_a, info->lst_a_count);
	info->lst_a_count -= 1;
	ft_printf("pb\n");
	info->action_count++;
	return (1);
}
