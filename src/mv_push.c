/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:22:19 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/31 19:32:30 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*b_first;

	if (ft_lstsize(*b) < 1)
		return ;
	b_first = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, b_first);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*a_first;

	if (ft_lstsize(*a) < 1)
		return ;
	a_first = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, a_first);
}
