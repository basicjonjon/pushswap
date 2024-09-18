/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:47 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/10 15:36:33 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	*ft_parse_arg(int argc, char **argv)
// {
// 	int		*res;
// 	char	**num;
// 	int		i;
// 	int		y;

// 	i = 0;
// 	y = 1;
// 	res = NULL;
// 	num = NULL;
// 	if (!ft_verif_argv_is_string(argc, argv))
// 	{
// 	}
// 	else
// 	{
// 		num = ft_split(argv[1], ' ');
// 		while (num[i])
// 			i++;
// 		res = malloc(sizeof(int) * (i - 1));
// 		if (!res)
// 			return (NULL);
// 		i = 0;
// 		y = 0;
// 		if (!res)
// 			return (NULL);
// 		while (i < ft_count_args_string(argv[1]))
// 			res[i++] = ft_atoi(num[y++]);
// 	}
// 	return (res);
// }

int	*ft_parse_separate_args(int argc, char **argv)
{
	int	*res;
	int	i;
	int	y;

	i = 0;
	y = 1;
	res = malloc(sizeof(int) * argc - 1);
	if (!res)
		return (NULL);
	while (i < (argc - 1))
		res[i++] = ft_atoi(argv[y++]);
	return (res);
}

int	ft_count_args_string(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
		{
			count++;
			i++;
		}
		while ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
			i++;
	}
	return (count);
}

int	*ft_parse_string_args(char **argv)
{
	int		*res;
	char	**num;
	int		i;

	i = 0;
	res = malloc(sizeof(int) * ft_count_args_string(argv[1]));
	if (!res)
		return (NULL);
	num = ft_split(argv[1], ' ');
	if (!num)
	{
		free(res);
		return (NULL);
	}
	while (num[i])
	{
		res[i] = ft_atoi(num[i]);
		i++;
	}
	ft_free_bidimentional_tab(num);
	return (res);
}
