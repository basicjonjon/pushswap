/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:04:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:31:14 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | (c >= '0' & c <= '9'))
		return (1);
	return (0);
}
