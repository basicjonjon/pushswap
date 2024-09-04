/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:32:52 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/26 11:14:41 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit_evolved(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi_evolved(const char *str)
{
	int		i;
	int		count;
	long	res;

	i = 0;
	count = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			count++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (count % 2)
		res *= -1;
	if (res < -2147483648 || res > 2147483647)
		return (1);
	return (0);
}

int	is_not_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit_evolved(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_not_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi_evolved(str))
			return (1);
		i++;
	}
	return (0);
}

int	ft_verif_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_not_number(argv[i]) || is_not_integer(argv[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
