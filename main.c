/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/19 13:50:10 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_info	*init_struct(int argc, char **argv)
{
	t_info	*res;

	res = malloc(sizeof(t_info) * 1);
	res->argc = argc;
	res->lst_b_count = 0;
	res->lst_a_count = argc - 1;
	res->action_count = 0;
	res->lst_a = init_list(argv, argc, 'a');
	res->lst_b = init_list(argv, argc, 'b');
	res->upper = ft_get_upper(res->lst_a, res->lst_a_count);
	res->lower = ft_get_lower(res->lst_a, res->lst_a_count);
	return (res);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc <= 2 || !argv)
		return (1);
	info = init_struct(argc, argv);
	print_lst(info);
	if (info->lst_a_count <= 3)
		triforce(info);
	else if (info->lst_a_count <= 5)
		five_num(info);
	else
		undred_num(info);
	ft_printf("nb coup = %s %i %s", GREEN, info->action_count, NC);
	return (0);
}
