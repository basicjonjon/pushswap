/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:03:12 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/18 12:49:01 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	args_have_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] != ' ' && s[i] != '-'
				&& s[i] != '+'))
			return (1);
		i++;
	}
	return (0);
}

int	str_intmin_intmax(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num < -2147483648 || num > 2147483647)
	{
		return (1);
	}
	return (0);
}

int	args_have_intmin_intmax(int argc, char **argv)
{
	char	**num;
	int		i;

	num = NULL;
	i = 0;
	if (argc == 2 && verif_is_string(argv[1]))
	{
		num = ft_split(argv[1], ' ');
		if (!num)
			return (1);
		while (num[i])
		{
			if (str_intmin_intmax(num[i++]))
				return (ft_free_bidimentional_tab(num), 1);
		}
		ft_free_bidimentional_tab(num);
	}
	else
	{
		while (i < argc)
			if (str_intmin_intmax(argv[i++]))
				return (1);
	}
	return (0);
}

int	num_have_duplicate(int *lst_num, int lst_count)
{
	int	i;
	int	y;

	y = 0;
	while (y < lst_count)
	{
		i = y + 1;
		while (i < lst_count)
		{
			if (lst_num[i] == lst_num[y])
			{
				return (1);
			}
			i++;
		}
		y++;
	}
	return (0);
}
