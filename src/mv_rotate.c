/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:29:24 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/31 19:39:03 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*a_first;

	if (ft_lstsize(*a) < 2)
		return ;
	a_first = *a;
	*a = (*a)->next;
	a_first->next = 0;
	ft_lstadd_back(a, a_first);
}

void	rotate_b(t_list **b)
{
	t_list	*b_first;

	if (ft_lstsize(*b) < 2)
		return ;
	b_first = *b;
	*b = (*b)->next;
	b_first->next = 0;
	ft_lstadd_back(b, b_first);
}
