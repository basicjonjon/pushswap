/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:03:05 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/24 18:29:53 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_get_next(t_info *info, int index)
{
	int	i;
	int	tmp_i;

	if (info->lst_b[index] == info->upper)
		return (2147483649);
	i = 0;
	tmp_i = ft_get_upper_index(info);
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] > info->lst_b[index]
			&& info->lst_a[i] < info->lst_a[tmp_i])
			tmp_i = i;
		i++;
	}
	return (tmp_i);
}

long	ft_get_preview(t_info *info, int index)
{
	int	i;
	int	tmp_i;

	if (info->lst_b[index] == info->lower)
		return (2147483649);
	i = 0;
	tmp_i = ft_get_lower_index(info);
	while (i < info->lst_a_count)
	{
		if (info->lst_a[i] < info->lst_b[index]
			&& info->lst_a[i] > info->lst_a[tmp_i])
			tmp_i = i;
		i++;
	}
	return (tmp_i);
}

t_move	ft_get_worth_move(t_info *info, int index)
{
	long	preview;
	long	next;
	t_move	res;

	preview = ft_get_preview(info, index);
	next = ft_get_next(info, index);
	res.negative = 0;
	if (next < preview + 1)
	{
		res.type = 'n';
		res.nb_coup = next;
		if (next > (info->lst_a_count / 2))
			res.nb_coup -= info->lst_a_count;
		if (res.nb_coup < 0)
			res.negative = 1;
		return (res);
	}
	res.type = 'p';
	res.nb_coup = preview;
	if (preview > (info->lst_a_count / 2))
		res.nb_coup -= info->lst_a_count;
	if (res.nb_coup < 0)
		res.negative = 1;
	return (res);
}

t_move	ft_get_2_worth_move(t_info *info, int index)
{
	long	preview;
	long	next;
	t_move	res;

	preview = ft_get_preview(info, index);
	next = ft_get_next(info, index);
	res.negative = 0;
	if (next < preview + 1)
	{
		res.type = 'n';
		res.nb_coup = next;
		if (next > (info->lst_a_count / 2))
			res.nb_coup -= info->lst_a_count;
		if (res.nb_coup < 0)
			res.negative = 1;
		return (res);
	}
	res.type = 'p';
	res.nb_coup = preview;
	if (preview > (info->lst_a_count / 2))
		res.nb_coup -= info->lst_a_count;
	if (res.nb_coup < 0)
		res.negative = 1;
	return (res);
}