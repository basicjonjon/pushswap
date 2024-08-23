/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:47:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:48:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rrotate_a(t_info *info, char mod)
{
	int	i;
	int	tmp_value;

	if (info->lst_a_count <= 1)
		return (-1);
	i = info->lst_a_count - 1;
	tmp_value = info->lst_a[i];
	while (i >= 0)
	{
		info->lst_a[i] = info->lst_a[i - 1];
		i--;
	}
	info->lst_a[0] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("rra\n");
	info->action_count++;
	return (1);
}

int	ft_rrotate_b(t_info *info, char mod)
{
	int	i;
	int	tmp_value;

	if (info->lst_b_count <= 1)
		return (-1);
	i = info->lst_b_count - 1;
	tmp_value = info->lst_b[i];
	while (i >= 0)
	{
		info->lst_b[i] = info->lst_b[i - 1];
		i--;
	}
	info->lst_b[0] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("rrb\n");
	info->action_count++;
	return (1);
}

int	ft_rrotate_all(t_info *info)
{
	if (info->lst_a_count <= 1 || info->lst_b_count <= 1)
		return (-1);
	ft_rrotate_a(info, 'b');
	ft_rrotate_b(info, 'b');
	ft_printf("rrr\n");
	info->action_count++;
	return (1);
}
