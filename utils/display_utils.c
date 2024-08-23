/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:24:38 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:47:22 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_lst(t_info *info_lst)
{
	int	i;

	i = 0;
	while (i < (info_lst->argc - 1))
	{
		if (i < info_lst->lst_a_count)
			ft_printf("%i", info_lst->lst_a[i]);
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (i < info_lst->lst_b_count)
			ft_printf("%i\n", info_lst->lst_b[i]);
		else
			ft_printf(" \n");
		i++;
	}
	ft_printf("_   _\n");
	ft_printf("a | b\n\n");
}
