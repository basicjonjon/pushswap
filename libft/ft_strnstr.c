/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:15:17 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/28 14:26:12 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *search, const char *find, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (ft_strlen(find) == 0)
		return ((char *)search);
	while (i < n && search[i] != '\0')
	{
		y = 0;
		if (search[i] == find[y])
		{
			while (search[i + y] == find[y] && find[y] != '\0' && (i + y) < n)
				y++;
			if (y == ft_strlen(find))
				return ((char *)&search[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%s", ft_strnstr("comment", "hey salut, comment va ?"));
// }