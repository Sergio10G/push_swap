/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:57:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/01 19:45:58 by sdiez-ga         ###   ########.fr       */
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
int	ft_lst_contains(t_list *head, int n);

	/* input_parse.c functions */
int		parse_nums(int argc, char **argv, t_list **a);
void	process_num(int num, char **nums, int num_index, t_list **a);
void	check_order_rpt(t_list **a);
void	free_matrix(char **mat);
int		str_is_zero(char *num);

	/* error_comp.c functions */
void	error();

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

#endif
