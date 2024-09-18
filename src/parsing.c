/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:51:26 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/12 17:00:57 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_parse_args(int argc, char **argv)
{
	int	*res;

	res = NULL;
	if (argc == 2)
	{
		if (verif_is_string(argv[1]))
			res = ft_parse_string_args(argv);
		else
			return (NULL);
	}
	else
	{
		res = ft_parse_separate_args(argc, argv);
	}
	if (!res)
		return (NULL);
	return (res);
}
