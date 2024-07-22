/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:19:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/06/01 13:24:11 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	f_n;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	f_n = (n % 10) + '0';
	write(fd, &f_n, 1);
}

// int main(void)
// {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
// 	if (fd == -1)
// 	{
// 		return 1;
// 	}
// 	ft_putnbr_fd(42, fd);
// 	close(fd);
// }