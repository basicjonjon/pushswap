/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/24 17:30:54 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*init_struct(int argc, char **argv)
{
	t_info	*res;

	res = malloc(sizeof(t_info) * 1);
	res->lst_a = init_list(argv, argc, 'a');
	res->lst_b = init_list(argv, argc, 'b');
	res->lst_a_count = argc - 1;
	res->lst_b_count = 0;
	res->action_count = 0;
	res->argc = argc;
	res->lower = ft_get_lower(res);
	res->upper = ft_get_upper(res);
	return (res);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_move	move;
	int		i;
	int		y;

	if (argc <= 2)
		return (1);
	y = 0;
	info = init_struct(argc, argv);
	print_lst(info);
	ft_push_b(info);
	info->action_count++;
	while (info->lst_a_count != 0)
	{
		i = 0;
		move = ft_get_worth_move(info, 0);
		if (move.negative)
			move.nb_coup *= -1;
		while (i < move.nb_coup)
		{
			if (move.negative)
			{
				ft_rrotate_a(info, 'a');
				info->action_count++;
			}
			else
			{
				ft_rotate_a(info, 'a');
				info->action_count++;
			}
			i++;
		}
		ft_push_b(info);
		info->action_count++;
		if (move.type == 'p' && ft_get_worth_move(info, 1).nb_coup != 0 && ft_get_worth_move(info, 1).negative)
		{
			ft_rrotate_all(info);
			info->action_count++;
		}
		else if (move.type == 'p' && ft_get_worth_move(info, 1).nb_coup != 0)
		{
			ft_rotate_all(info);
			info->action_count++;
		}
		else if (move.type == 'p')
		{
			ft_rotate_b(info, 'a');
			info->action_count++;
		}
		y++;
	}
	while (info->lst_b_count != 0)
	{
		ft_push_a(info);
		info->action_count++;
	}
	
	print_lst(info);
	ft_printf("nb coup : %s[%i]%s\n",GREEN, info->action_count, NC);
	return (0);
}
