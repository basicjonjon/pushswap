/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:14:50 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/28 13:56:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

// int main(void)
// {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     if (fd == -1)
// 	{
//         return 1;
//     }
// 	ft_putendl_fd("Hello World!", fd);
// 	close(fd);
// }