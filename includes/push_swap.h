/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:57:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/09 20:16:07 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	Libraries
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

//	Functions
	/* push_swap.c functions */


	/* list_funcs.c functions */
int		ft_lst_contains(t_list *head, int n);
int		lst_is_ordered(t_list **lst);
int		get_min_index(t_list **a);
void	rotate_min_to_top(t_list **a);

	/* input_parse.c functions */
int		parse_nums(int argc, char **argv, t_list **a);
void	process_num(int num, char **nums, int num_index, t_list **a);
void	check_order_rpt(t_list **a);
void	free_matrix(char **mat);
int		str_is_zero(char *num);

	/* error_comp.c functions */
void	error();
void	error_quiet();

	/* mv_swap.c functions */
void	swap(t_list **lst);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ab(t_list **a, t_list **b);

	/* mv_push.c functions */
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

	/* mv_rotate.c functions */
void	rotate(t_list **list);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);

	/* mv_reverse_rotate.c functions */
void	reverse_rotate(t_list **list);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_ab(t_list **a, t_list **b);

	/* arrange_small.c functions */
void	arrange_3(t_list **a);
void	arrange_10(t_list **a, t_list **b);

	/* utils.c functions */
void	ft_putstr(char *str);

#endif
