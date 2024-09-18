/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:17:58 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/16 11:25:48 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (args_have_char(argv[i]))
			return (1);
		i++;
	}
	if (args_have_intmin_intmax(argc, argv))
		return (1);
	return (0);
}
