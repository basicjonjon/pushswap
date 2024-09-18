/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:07 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/18 12:49:35 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (ft_error(argc, argv))
		return (ft_puterror(NULL), 1);
	info = init_info(argc, argv);
	if (num_have_duplicate(info.lst_a, info.lst_a_count))
		return (free_all(&info), ft_puterror(NULL), 1);
	if (verif_is_finish(info))
		return (free_all(&info), 0);
	if (info.lst_a_count == 3)
		triforce(&info);
	else
		turk_sort(&info);
	return (free_all(&info), 0);
}
