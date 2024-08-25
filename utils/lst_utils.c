/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:51:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 16:05:59 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_up_lst(int *lst, int count_lst)
{
	int	i;

	if (count_lst == 0)
		return (-1);
	i = 1;
	while (i <= count_lst - 1)
	{
		lst[i - 1] = lst[i];
		i++;
	}
	lst[i - 1] = 0;
	return (0);
}

int	ft_down_lst(int *lst, int count_lst)
{
	int	i;

	if (count_lst == 0)
		return (-1);
	i = count_lst - 1;
	while (i > 0)
	{
		lst[i] = lst[i - 1];
		i--;
	}
	lst[0] = 0;
	return (0);
}

int	*init_list(char **argv, int argc, char type)
{
	int	i;
	int	y;
	int	*res;

	i = 0;
	y = 1;
	if (type == 'a')
	{
		res = malloc(sizeof(int) * (argc - 1));
		if (!res)
		{
			return (NULL);
		}
		while (i < (argc - 1))
			res[i++] = ft_atoi(argv[y++]);
	}
	else
	{
		res = ft_calloc(argc, sizeof(int));
		if (!res)
		{
			return (NULL);
		}
	}
	return (res);
}

void	update_info(t_info *info)
{
	info->a_upper_i = ft_get_upper_i(info->lst_a, info->lst_a_count);
	info->a_lower_i = ft_get_lower_i(info->lst_a, info->lst_a_count);
	info->b_upper_i = ft_get_upper_i(info->lst_b, info->lst_b_count);
	info->b_lower_i = ft_get_lower_i(info->lst_b, info->lst_b_count);
}
