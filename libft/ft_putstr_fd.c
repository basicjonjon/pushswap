/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:09:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/28 14:17:18 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

// int main(void)
// {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     if (fd == -1) 
//         return 1;
// 	ft_putstr_fd("Hello World!", fd);
// 	close(fd);
// }