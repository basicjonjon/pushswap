/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:39:25 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/21 16:13:18 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define NC "\033[0m"

# include "libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_info
{
	int	argc;
	int	a_lower_i;
	int	a_upper_i;
	int	b_lower_i;
	int	b_upper_i;
	int	*lst_a;
	int	*lst_b;
	int	lst_a_count;
	int	lst_b_count;
	int	action_count;
}		t_info;

typedef struct s_cheap_num
{
	int	index_a;
	int index_b;
	int score;
}		t_cheap;

void	print_lst(t_info *info_lst);
void	print_lst_color(t_info *info_lst, int index);
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
void	turk_sort(t_info *info);

#endif