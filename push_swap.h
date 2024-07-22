/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:39:25 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/22 18:59:55 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_info
{
	int	*lst_a;
	int	lst_a_count;
	int	*lst_b;
	int	lst_b_count;
	int	lower;
	int	upper;
	int	argc;
	int	action_count;
}		t_info;

int		*init_list(char **argv, int argc, char type);
void	print_lst(t_info *info_lst);
int		ft_up_lst(int *lst, int count_lst);
int		ft_down_lst(int *lst, int count_lst);

int		ft_get_lower(int *lst_a, int lst_a_count);
int		ft_get_lower_index(int *lst_a, int lst_a_count);
int		ft_get_upper(int *lst_a, int lst_a_count);
int		ft_get_upper_index(int *lst_a, int lst_a_count);
int		ft_verif_finish(int *lst_a, int argc, int count_a);

int		ft_swap_a(t_info *info, char mod);
int		ft_swap_b(t_info *info, char mod);
int		ft_swap_all(t_info *info);

int		ft_rotate_a(t_info *info, char mod);
int		ft_rotate_b(t_info *info, char mod);
int		ft_rotate_all(t_info *info);

int		ft_rrotate_a(t_info *info, char mod);
int		ft_rrotate_b(t_info *info, char mod);
int		ft_rrotate_all(t_info *info);

int		ft_push_b(t_info *info);
int		ft_push_a(t_info *info);

#endif