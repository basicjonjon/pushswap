/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/12 17:14:09 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate(int *lst, int lst_count, char lst_name)
{
	int	i;
	int	tmp_value;
	
	if (lst_count <= 1)
		return (-1);
	i = 1;
	tmp_value = lst[0];
	while (i < lst_count)
	{
		lst[i - 1] = lst[i];
		i++;
	}
	lst[i - 1] = tmp_value;
	if (lst_name == 'a' || lst_name == 'b')
		ft_printf("r%c\n", lst_name);
	return (0);
}

int	ft_rotate_all(int *lst_a, int *lst_b, int lst_count_a, int lst_count_b)
{
	if (lst_count_a <= 1 || lst_count_b <= 1)
		return (-1);
	ft_rotate(lst_a, lst_count_a, 'c');
	ft_rotate(lst_b, lst_count_b, 'c');
	ft_printf("rr");
	return (0);
}

int	ft_rrotate(int *lst, int lst_count, char lst_name)
{
	int	i;
	int	tmp_value;
	
	if (lst_count <= 1)
		return (-1);
	i = lst_count - 1;
	tmp_value = lst[i];
	while (i >= 0)
	{
		lst[i] = lst[i - 1];
		i--;
	}
	lst[0] = tmp_value;
	if (lst_name == 'a' || lst_name == 'b')
		ft_printf("rr%c\n", lst_name);
	return (0);
}

int	ft_rrotate_all(int *lst_a, int *lst_b, int lst_count_a, int lst_count_b)
{
	if (lst_count_a <= 1 || lst_count_b <= 1)
		return (-1);
	ft_rrotate(lst_a, lst_count_a, 'c');
	ft_rrotate(lst_b, lst_count_b, 'c');
	ft_printf("rrr");
	return (0);
}