/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:08:12 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/28 14:10:47 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c % 256)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
