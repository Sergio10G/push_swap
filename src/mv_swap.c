/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:32:54 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/31 19:29:34 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	*lst = (*lst)->next;
	aux->next = (*lst)->next;
	(*lst)->next = aux;
}

void	swap_a(t_list **a)
{
	if (ft_lstsize(*a) < 2)
		return ;
	swap(a);
}

void	swap_b(t_list **b)
{
	if (ft_lstsize(*b) < 2)
		return ;
	swap(b);
}

void	swap_ab(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	swap(a);
	swap(b);
}
