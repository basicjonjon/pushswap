/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:39:25 by jle-doua          #+#    #+#             */
/*   Updated: 2024/09/12 17:23:30 by jle-doua         ###   ########.fr       */
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
	int	index_b;
	int	score;
	int	a_reverse;
	int	b_reverse;
}		t_cheap;

int		ft_error(int argc, char **argv);

int		args_have_char(char *s);
int		args_have_intmin_intmax(int argc, char **argv);

void	free_all(t_info *info);
void	ft_free_bidimentional_tab(char **tab);

int		*ft_parse_args(int argc, char **argv);

int		*ft_parse_separate_args(int argc, char **argv);
int		ft_count_args_string(char *s);
int		*ft_parse_string_args(char **argv);

int		verif_is_string(char *s);

int		*init_list_b(int argc);
int		ft_up_lst(int *lst, int count_lst);
int		ft_down_lst(int *lst, int count_lst);

int		ft_get_lower_i(int *lst, int lst_count);
int		ft_get_upper_i(int *lst, int lst_count);

t_info	init_info(int argc, char **argv);

void	print_lst(t_info *info_lst);

int		num_have_duplicate(int *lst_num, int lst_count);

void	triforce(t_info *info);

void	update_info(t_info *info);

int		ft_push_b(t_info *info);
int		ft_push_a(t_info *info);

int		ft_rotate_a(t_info *info, char mod);
int		ft_rotate_b(t_info *info, char mod);
int		ft_rotate_all(t_info *info);

int		ft_rrotate_a(t_info *info, char mod);
int		ft_rrotate_b(t_info *info, char mod);
int		ft_rrotate_all(t_info *info);

int		ft_swap_b(t_info *info, char mod);
int		ft_swap_a(t_info *info, char mod);
int		ft_swap_all(t_info *info);

int		get_target(t_info *info, int num);
int		get_target_reverse(t_info *info, int num);

t_cheap	get_cost(t_info *info, int index_num);
t_cheap	get_cost_reverse(t_info *info, int index_num);

t_cheap	get_hit(t_info *info, int mod);

void	turk_sort(t_info *info);

int		r_all(t_info *info, t_cheap hit);
void	move_list(t_info *info, int mod);

int		verif_is_finish(t_info info);
#endif