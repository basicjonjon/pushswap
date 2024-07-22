/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:19:21 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/17 11:37:41 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(int *lst_start, int *lst_end, int *count_start, int *count_end,
		char name_lst)
{
	int tmp_value;
	if (*count_start <= 0)
		return (-1);
	tmp_value = lst_start[0];
	*count_end += 1;
	ft_down_lst(lst_end, *count_end);
	lst_end[0] = tmp_value;
	ft_up_lst(lst_start, *count_start);
	*count_start -= 1;
	if (name_lst == 'a' || name_lst == 'b')
		ft_printf("p%c\n", name_lst);
	if (name_lst == 'a')
		return (1);
	else 
		return (2);
}
