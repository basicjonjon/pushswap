/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:05:55 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/28 14:14:24 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count[2];
	char	*res;
	size_t	s1size;
	size_t	s2size;

	count[0] = 0;
	count[1] = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1size + s2size) + 1);
	if (!res)
		return (0);
	while (s1[count[1]])
		res[count[0]++] = s1[count[1]++];
	count[1] = 0;
	while (s2[count[1]])
		res[count[0]++] = s2[count[1]++];
	res[s1size + s2size] = '\0';
	return (res);
}
// int	main(void)
// {
// 	char s1[]= "hello ";
// 	char s2[]= "world !";

// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }
