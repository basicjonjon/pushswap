/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undred_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:42:39 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/20 17:29:30 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_prev_prevision(int *lst, int start, int nb, t_info *info)
{
	int	i;
	int	index;
	int	x;

	i = start + 1;
	index = ft_get_lower_i(lst, info->lst_a_count);
	while (i % info->lst_a_count != start)
	{
		x = ' ';
		if (lst[i % info->lst_a_count] < nb && lst[i
			% info->lst_a_count] > lst[index])
		{
			index = i % info->lst_a_count;
		}
		i++;
	}
	return (index);
}

int	get_next_prevision(int *lst, int start, int nb, t_info *info)
{
	int	i;
	int	index;
	int	x;

	i = start + 1;
	index = ft_get_upper_i(lst, info->lst_a_count);
	while (i % info->lst_a_count != start)
	{
		x = ' ';
		if (lst[i % info->lst_a_count] > nb && lst[i
			% info->lst_a_count] < lst[index])
		{
			x = 'X';
			index = i % info->lst_a_count;
		}
		i++;
	}
	return (index);
}

int	get_next_number_i(int *lst, int start, int nb, t_info *info)
{
	int	i;
	int	index;

	i = start;
	index = ft_get_upper_i(lst, info->lst_a_count);
	while (i != info->lst_a_count)
	{
		if (lst[i % info->lst_a_count] >= nb && lst[i
			% info->lst_a_count] < lst[index])
		{
			index = i % info->lst_a_count;
		}
		i++;
	}
	return (index);
}

int	get_prev_number_i(int *lst, int start, int nb, t_info *info)
{
	int	i;
	int	index;

	i = start;
	index = ft_get_lower_i(lst, info->lst_a_count);
	while (i != info->lst_a_count)
	{
		if (lst[i % info->lst_a_count] <= nb && lst[i
			% info->lst_a_count] > lst[index])
		{
			index = i % info->lst_a_count;
		}
		i++;
	}
	return (index);
}

typedef struct s_move
{
	char	type;
	int		b_l;
	int		b_u;
}			t_move;



t_move	get_worth_move(t_info *info)
{
	int		lower_index;
	int		lower_sec;
	int		upper_index;
	int		upper_sec;
	t_move	best;

	lower_index = get_prev_number_i(info->lst_a, 0, info->lst_b[0], info);
	lower_sec = get_prev_prevision(info->lst_a, lower_index,
			info->lst_a[lower_index], info);
	upper_index = get_next_number_i(info->lst_a, 0, info->lst_b[0], info);
	upper_sec = get_next_prevision(info->lst_a, upper_index,
			info->lst_a[upper_index], info);
	best.b_l = (lower_sec - lower_index) + lower_index;
	best.b_u = (upper_sec - upper_index) + upper_index;
	if (best.b_l < 0)
		best.b_l *= -1;
	if (best.b_u < 0)
		best.b_u *= -1;
	if (best.b_l < best.b_u || info->lst_b[0] == info->upper)
		best.type = 'l';
	else
		best.type = 'u';
	return (best);
}

void	undred_num(t_info *info)
{
	int		y;
	int		z;
	int		i;
	int		nb_tour;
	int		nb_r;
	int		reverse;
	t_move	best;

	nb_tour = 2;
	ft_push_b(info);
	y = 0;
	while (info->lst_a_count != 0)
	{
		if (info->lst_a_count == 1)
			nb_tour = 1;
		best = get_worth_move(info);
		i = 0;
		while (i < nb_tour)
		{
			reverse = 0;
			if (best.type == 'l')
				nb_r = get_prev_number_i(info->lst_a, 0, info->lst_b[0], info);
			else
				nb_r = get_next_number_i(info->lst_a, 0, info->lst_b[0], info);
			z = 0;
			if (nb_r > info->lst_a_count / 2)
			{
				nb_r =  info->lst_a_count - nb_r;
				reverse = 1;
			}
			while (z < nb_r)
			{
				if (!reverse)
					ft_rotate_a(info, 'a');
				else
					ft_rrotate_a(info, 'a');
				z++;
			}
			ft_push_b(info);
			if (best.type == 'l')
				ft_rotate_b(info, 'a');
			i++;
		}
		y++;
	}
	print_lst(info);
}
