/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:51:22 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/08 13:41:50 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(unsigned int n, char *base)
{
	long	cpy_n;
	int		baselen;
	int		i;

	cpy_n = n;
	baselen = ft_strlen(base);
	i = 0;
	if (cpy_n >= baselen)
		i = ft_putnbrbase(cpy_n / baselen, base);
	ft_putchar(base[(cpy_n % baselen)]);
	return (++i);
}
