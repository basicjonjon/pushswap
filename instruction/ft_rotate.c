/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/18 14:36:34 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rotate_a(t_info *info, char mod)
{
	int	i;
	int	tmp_value;
	
	if (info->lst_a_count <= 1)
		return (-1);
	i = 1;
	tmp_value = info->lst_a[0];
	while (i < info->lst_a_count)
	{
		info->lst_a[i - 1] = info->lst_a[i];
		i++;
	}
	info->lst_a[i - 1] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("ra\n");
	info->action_count++;
	return (1);
}

int	ft_rotate_b(t_info *info, char mod)
{
	int	i;
	int	tmp_value;
	
	if (info->lst_b_count <= 1)
		return (-1);
	i = 1;
	tmp_value = info->lst_b[0];
	while (i < info->lst_b_count)
	{
		info->lst_b[i - 1] = info->lst_b[i];
		i++;
	}
	info->lst_b[i - 1] = tmp_value;
	if (mod == 'b')
		return (1);
	ft_printf("rb\n");
	info->action_count++;
	return (1);
}

int	ft_rotate_all(t_info *info)
{
	if (info->lst_b_count <= 1 || info->lst_b_count <= 1)
		return (-1);
	ft_rotate_a(info, 'b');
	ft_rotate_b(info, 'b');
	ft_printf("rr\n");
	info->action_count++;
	return (0);
}

