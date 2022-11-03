/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:08:36 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/02 14:36:17 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_free_lst(t_list **lst)
{
	if (*lst)
		ft_lstclear(lst);
	error();
}

void	error_free_chk(t_list **a, t_list **b, char *input)
{
	if (*a)
		ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	if (input)
		free(input);
	error();
}

void	error_quiet(void)
{
	exit(1);
}
