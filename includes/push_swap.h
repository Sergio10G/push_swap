/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:57:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/31 18:58:07 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	Libraries
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

//	Functions
	/* lst_funcs.c functions */
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

#endif
