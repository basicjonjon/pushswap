/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/22 17:09:49 by jle-doua         ###   ########.fr       */
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
	res->action_count = 0;
	res->lower = ft_get_lower(res->lst_a, res->lst_a_count);
	res->upper = ft_get_upper(res->lst_a, res->lst_a_count);
	return (res);
}

int	main(int argc, char **argv)
{
	t_info	*info_lst;
	t_move	*b_move;
	int		i;
	int		y;

	if (argc <= 2)
		return (1);
	y = 0;
	i = 0;
	info_lst = init_struct(argc, argv);
	print_lst(info_lst);
	ft_push(info_lst->lst_a, info_lst->lst_b, &info_lst->lst_a_count,
		&info_lst->lst_b_count, 'b');
	print_lst(info_lst);
	while (info_lst->lst_a_count != 0)
	{
		b_move = ft_get_worth_move(info_lst);
		if (b_move->type == 'p')
		{
			i = 0;
			if (b_move->nb_coup[0] < 0)
			{
				while (i < (b_move->nb_coup[0] * -1))
				{
					ft_rrotate(info_lst->lst_a, info_lst->lst_a_count, 'a');
					print_lst(info_lst);
					info_lst->action_count++;
					i++;
				}
				ft_push(info_lst->lst_a, info_lst->lst_b,
					&info_lst->lst_a_count, &info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
				ft_rotate(info_lst->lst_b, info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
			}
			else
			{
				while (i < b_move->nb_coup[0])
				{
					ft_rotate(info_lst->lst_a, info_lst->lst_a_count, 'a');
					print_lst(info_lst);
					info_lst->action_count++;
					i++;
				}
				ft_push(info_lst->lst_a, info_lst->lst_b,
					&info_lst->lst_a_count, &info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
				ft_rotate(info_lst->lst_b, info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
			}
		}
		else if (b_move->type == 'n')
		{
			i = 0;
			printf("type : [%c]\n", b_move->type);
			if (b_move->nb_coup[0] < 0)
			{
				
				while (i < (b_move->nb_coup[0] * -1))
				{
					ft_rrotate(info_lst->lst_a, info_lst->lst_a_count, 'a');
					print_lst(info_lst);
					info_lst->action_count++;
					i++;
				}
				ft_push(info_lst->lst_a, info_lst->lst_b,
					&info_lst->lst_a_count, &info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
			}
			else
			{
				while (i < b_move->nb_coup[0])
				{
					ft_rotate(info_lst->lst_a, info_lst->lst_a_count, 'a');
					print_lst(info_lst);
					info_lst->action_count++;
					i++;
				}
				ft_push(info_lst->lst_a, info_lst->lst_b,
					&info_lst->lst_a_count, &info_lst->lst_b_count, 'b');
				print_lst(info_lst);
				info_lst->action_count++;
			}
		}
		print_lst(info_lst);
		y++;
	}
	while (info_lst->lst_b_count != 0)
	{
		ft_push(info_lst->lst_b, info_lst->lst_a, &info_lst->lst_b_count,
			&info_lst->lst_a_count, 'a');
		info_lst->action_count++;
	}
	print_lst(info_lst);
	printf("action : %i", info_lst->action_count);
	return (0);
}
