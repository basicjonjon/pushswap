/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/25 16:10:38 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_info	*init_struct(int argc, char **argv)
{
	t_info	*res;

	res = malloc(sizeof(t_info) * 1);
	if (!res)
		return (NULL);
	res->argc = argc;
	res->lst_b_count = 0;
	res->lst_a_count = argc - 1;
	res->action_count = 0;
	res->lst_a = init_list(argv, argc, 'a');
	if (!res->lst_a)
		return (free(res), NULL);
	res->lst_b = init_list(argv, argc, 'b');
	if (!res->lst_b)
		return (free(res), free(res->lst_a), NULL);
	res->a_upper_i = ft_get_upper_i(res->lst_a, res->lst_a_count);
	res->a_lower_i = ft_get_lower_i(res->lst_a, res->lst_a_count);
	return (res);
}

void	free_all(t_info *info)
{
	free(info->lst_a);
	free(info->lst_b);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc <= 2 || ft_verif_args(argc, argv))
	{
		ft_puterror(NULL);
		return (1);
	}
	info = init_struct(argc, argv);
	if (!info)
	{
		ft_puterror(NULL);
		return (1);
	}
	if (repeat_verification(info))
	{
		ft_puterror(NULL);
		free_all(info);
		return (1);
	}
	if (argc - 1 <= 3)
		triforce(info);
	else
		turk_sort(info);
	free_all(info);
	return (0);
}
