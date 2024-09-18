/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:41:10 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/12 17:01:11 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_info	init_info(int argc, char **argv)
{
	t_info	info;

	info.lst_a = ft_parse_args(argc, argv);
	if (info.lst_a == NULL)
		return ((t_info){0});
	info.lst_a_count = argc - 1;
	info.argc = argc;
	if (argc == 2 && verif_is_string(argv[1]))
	{
		info.lst_a_count = ft_count_args_string(argv[1]);
		info.lst_b = init_list_b(info.lst_a_count);
		info.argc = info.lst_a_count + 1;
	}
	else
		info.lst_b = init_list_b(info.lst_a_count);
	if (info.lst_b == NULL)
		return (free(info.lst_a), (t_info){0});
	info.lst_b_count = 0;
	info.a_lower_i = ft_get_lower_i(info.lst_a, info.lst_a_count);
	info.a_upper_i = ft_get_upper_i(info.lst_a, info.lst_a_count);
	info.b_upper_i = ft_get_upper_i(info.lst_b, info.lst_b_count);
	info.b_lower_i = ft_get_lower_i(info.lst_b, info.lst_b_count);
	info.action_count = 0;
	return (info);
}
