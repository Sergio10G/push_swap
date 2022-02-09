/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:16:56 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/09 19:48:48 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	arrange_3(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	if (lst_is_ordered(a))
		return ;
	n1 = (*a)->content;
	n2 = (*a)->next->content;
	n3 = (*a)->next->next->content;
	if (n1 < n2 && n1 > n3)
		reverse_rotate_a(a);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rotate_a(a);
	else
	{
		swap_a(a);
		arrange_3(a);
	}
}

void	arrange_10(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		rotate_min_to_top(a);
		push_b(a, b);
	}
	arrange_3(a);
	while (ft_lstsize(*b) > 0)
		push_a(a, b);
}
