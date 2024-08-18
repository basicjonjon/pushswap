/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:39:25 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/18 17:45:58 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define GREEN "\033[1;32m"
# define NC "\033[0m"

# include "libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_info
{
	int	argc;
	int	lower;
	int	upper;
	int	*lst_a;
	int	*lst_b;
	int	lst_a_count;
	int	lst_b_count;
	int	action_count;
}		t_info;

void	print_lst(t_info *info_lst);
int		ft_up_lst(int *lst, int count_lst);
int		ft_down_lst(int *lst, int count_lst);
int		*init_list(char **argv, int argc, char type);

int		ft_verif_finish(t_info *info);
int		ft_get_upper(int *lst, int lst_count);
int		ft_get_lower(int *lst, int lst_count);
int		ft_get_lower_i(int *lst, int lst_count);
int		ft_get_upper_i(int *lst, int lst_count);

int		ft_swap_all(t_info *info);
int		ft_swap_a(t_info *info, char mod);
int		ft_swap_b(t_info *info, char mod);

int		ft_rotate_all(t_info *info);
int		ft_rotate_a(t_info *info, char mod);
int		ft_rotate_b(t_info *info, char mod);

int		ft_rrotate_all(t_info *info);
int		ft_rrotate_a(t_info *info, char mod);
int		ft_rrotate_b(t_info *info, char mod);

int		ft_push_b(t_info *info);
int		ft_push_a(t_info *info);

void	triforce(t_info *info);
void	five_num(t_info *info);
void	undred_num(t_info *info);

#endif