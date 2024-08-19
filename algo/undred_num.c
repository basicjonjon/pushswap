/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undred_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:42:39 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/19 18:11:12 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	get_prev_score(int *lst, int start, int nb, t_info *info)
// {
// 	int	i;
// 	int	index;

// 	i = start + 1;
// 	index = ft_get_lower_i(lst, info->lst_a_count);
// 	while (i % info->lst_a_count != index)
// 	{
// 		if (lst[i % info->lst_a_count] < nb && lst[i
// 			% info->lst_a_count] > lst[index])
// 		{
// 			index = i % info->lst_a_count;
// 		}
// 		printf("test\n");
// 		i++;
// 	}
// 	return (index);
// }
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
			// printf("%s%i%s\n", GREEN, info->lst_a[index], NC);
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
	printf("%s%i%s\n", RED, info->lst_a[index], NC);
	while (i != info->lst_a_count)
	{
		if (lst[i % info->lst_a_count] <= nb && lst[i
			% info->lst_a_count] > lst[index])
		{
			index = i % info->lst_a_count;
			// printf("%s%i%s\n", GREEN, info->lst_a[index], NC);
		}
		i++;
	}
	return (index);
}

typedef struct s_move
{
	char	type;
	int		nb_coup;
}			t_move;

t_move	get_worth_move(t_info *info)
{
	int		lower_index;
	int		upper_index;
	t_move	best;

	lower_index = get_prev_number_i(info->lst_a, 0, info->lst_b[0], info);
	upper_index = get_next_number_i(info->lst_a, 0, info->lst_b[0], info);
	if (lower_index < upper_index)
	{
		best.type = 'l';
		best.nb_coup = lower_index;
	}
	else
	{
		best.type = 'u';
		best.nb_coup = upper_index;
	}
	return (best);
}

void	undred_num(t_info *info)
{
	int	i;
	t_move best;

	ft_push_b(info);
	while (info->lst_a_count != 0)
	{
		best = get_worth_move(info);
		i = -1;
		while (++i < best.nb_coup)
			ft_rotate_a(info, 'a');
		ft_push_b(info);
		if (best.type == 'l')
			ft_rotate_b(info, 'a');
	}
	while (info->lst_b_count != 0)
		ft_push_a(info);
	print_lst(info);
}
