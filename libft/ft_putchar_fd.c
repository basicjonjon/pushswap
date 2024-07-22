/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:56:05 by jle-doua          #+#    #+#             */
/*   Updated: 2024/05/24 10:17:40 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     if (fd == -1) 
//         return 1;
// 	ft_putchar_fd('c', fd);
// 	close(fd);
// }