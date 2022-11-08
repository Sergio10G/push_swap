/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:29:24 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/08 15:49:32 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **list)
{
	t_list	*lst_first;

	lst_first = *list;
	*list = (*list)->next;
	lst_first->next = 0;
	ft_lstadd_back(list, lst_first);
}

void	rotate_a(t_list **a)
{
	if (ft_lstsize(*a) < 2)
		return ;
	rotate(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_list **b)
{
	if (ft_lstsize(*b) < 2)
		return ;
	rotate(b);
	ft_putstr("rb\n");
}

void	rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
