/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:12:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 12:23:24 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	r_all(t_info *info, t_cheap hit)
{
	int	i;

	i = 0;
	if (hit.a_reverse == hit.b_reverse)
	{
		while (i < hit.index_a && i < hit.index_b)
		{
			if (hit.a_reverse)
				ft_rrotate_all(info);
			else
				ft_rotate_all(info);
			i++;
		}
	}
	return (i);
}

void	move_list(t_info *info, int mod)
{
	int		i;
	int		save_i;
	t_cheap	hit;

	hit = get_hit(info, mod);
	i = r_all(info, hit);
	save_i = i;
	while (i < hit.index_a)
	{
		if (hit.a_reverse)
			ft_rrotate_a(info, 'a');
		else
			ft_rotate_a(info, 'a');
		i++;
	}
	i = save_i;
	while (i < hit.index_b)
	{
		if (hit.b_reverse)
			ft_rrotate_b(info, 'a');
		else
			ft_rotate_b(info, 'a');
		i++;
	}
}
