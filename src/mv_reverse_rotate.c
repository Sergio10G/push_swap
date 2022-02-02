/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:11:37 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/02 17:18:02 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*s2last;

	last = ft_lstlast(*list);
	s2last = *list;
	while (s2last->next != last)
		s2last = s2last->next;
	s2last->next = 0;
	ft_lstadd_front(list, last);
}

void	reverse_rotate_a(t_list **a)
{
	if (ft_lstsize(*a) < 2)
		return ;
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	if (ft_lstsize(*b) < 2)
		return ;
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	ft_putstr("rrr\n");
}
