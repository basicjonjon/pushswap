/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:16:18 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:48:15 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_swap_a(t_info *info, char mod)
{
	int	tmp_value;

	if (info->lst_a_count <= 1)
		return (-1);
	tmp_value = info->lst_a[0];
	info->lst_a[0] = info->lst_a[1];
	info->lst_a[1] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("sa\n");
	info->action_count++;
	return (1);
}

int	ft_swap_b(t_info *info, char mod)
{
	int	tmp_value;

	if (info->lst_b_count <= 1)
		return (-1);
	tmp_value = info->lst_b[0];
	info->lst_b[0] = info->lst_b[1];
	info->lst_b[1] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("sb\n");
	info->action_count++;
	return (1);
}

int	ft_swap_all(t_info *info)
{
	if (info->lst_a_count <= 1 || info->lst_b_count <= 1)
		return (-1);
	ft_swap_a(info, 'b');
	ft_swap_b(info, 'b');
	ft_printf("ss\n");
	info->action_count++;
	return (1);
}
