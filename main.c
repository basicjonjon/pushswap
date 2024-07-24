/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/24 13:21:08 by jle-doua         ###   ########.fr       */
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
	res->lower = ft_get_lower(res);
	res->upper = ft_get_upper(res);
	return (res);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;
	int		y;

	if (argc <= 2)
		return (1);
	y = 0;
	i = 0;
	info = init_struct(argc, argv);
	print_lst(info);
	ft_push_b(info);
	print_lst(info);

	printf("[%i]\n",info->lst_a[ft_get_worth_move(info)]);
	return (0);
}
