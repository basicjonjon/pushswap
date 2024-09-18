/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:04:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/16 11:21:11 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verif_is_string(char *s)
{
	if (ft_count_args_string(s) > 1)
		return (1);
	return (0);
}

int	verif_is_finish(t_info info)
{
	int	i;

	i = 0;
	while (i < info.lst_a_count - 1)
	{
		if (info.lst_a[i] > info.lst_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
