/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:51:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/23 16:47:09 by jle-doua         ###   ########.fr       */
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
	while (i >= 0)
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
		while (i < (argc - 1))
			res[i++] = ft_atoi(argv[y++]);
	}
	else
		res = ft_calloc(argc, sizeof(int));
	return (res);
}

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
