/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:16:18 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/12 17:13:54 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(int *lst, int count_lst, char lst_name)
{
	int	tmp_value;

	if (count_lst <= 1)
		return (-1);
	tmp_value = lst[0];
	lst[0] = lst[1];
	lst[1] = tmp_value;
	if (lst_name == 'a' || lst_name == 'b')
		ft_printf("s%c\n",lst_name);
	if (lst_name == 'a')
		return (3);
	else if (lst_name == 'b')
		return (4);
	return (0);
}

int	ft_swap_all(int *lst_a, int *lst_b, int count_a, int count_b)
{
	if (count_a <= 1 || count_b <= 1)
		return (-1);
	ft_swap(lst_a, count_a, 'c');
	ft_swap(lst_b, count_b, 'c');
	ft_printf("ss\n");
	return (0);
}