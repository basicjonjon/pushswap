/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:51:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/19 13:53:29 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_up_lst(int *lst, int count_lst)
{
	int	i;

	if (count_lst == 0)
		return (-1);
	i = 1;
	while (i <= count_lst - 1)
	{
		lst[i - 1] = lst[i];
		i++;
	}
	lst[i - 1] = 0;
	return (0);
}

int	ft_down_lst(int *lst, int count_lst)
{
	int	i;

	if (count_lst == 0)
		return (-1);
	i = count_lst - 1;
	while (i >= 0)
	{
		lst[i] = lst[i - 1];
		i--;
	}
	lst[0] = 0;
	return (0);
}

int	*init_list(char **argv, int argc, char type)
{
	int	i;
	int	y;
	int	*res;

	i = 0;
	y = 1;
	if (type == 'a')
	{
		res = malloc(sizeof(int) * (argc - 1));
		while (i < (argc - 1))
			res[i++] = ft_atoi(argv[y++]);
	}
	else
		res = ft_calloc(argc, sizeof(int));
	return (res);
}

void	print_lst(t_info *info_lst)
{
	int	i;

	i = 0;
	while (i < (info_lst->argc - 1))
	{
		if (i < info_lst->lst_a_count)
			ft_printf("%i", info_lst->lst_a[i]);
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (i < info_lst->lst_b_count)
			ft_printf("%i\n", info_lst->lst_b[i]);
		else
			ft_printf(" \n");
		i++;
	}
	ft_printf("_   _\n");
	ft_printf("a | b\n\n");
}

void	print_lst_color(t_info *info_lst, int index)
{
	int	i;

	i = 0;
	while (i < (info_lst->argc - 1))
	{
		if (i < info_lst->lst_a_count)
		{
			if (i == index)
				ft_printf("%s%i%s", RED, info_lst->lst_a[i], NC);
			else
				ft_printf("%i", info_lst->lst_a[i]);
		}
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (i < info_lst->lst_b_count)
			ft_printf("%i\n", info_lst->lst_b[i]);
		else
			ft_printf(" \n");
		i++;
	}
	ft_printf("_   _\n");
	ft_printf("a | b\n\n");
}
