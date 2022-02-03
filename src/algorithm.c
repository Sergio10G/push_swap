/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:16:03 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/03 17:45:14 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	arrange(t_list **a, t_list **b)
{
	void	(*rot_ptr)(t_list **);
	int	smallest_pos;
	int	cur_pos;
	t_list	*lst_item;
	t_list	*smallest_item;

	while (ft_lstsize(*a))
	{
		smallest_pos = 0;
		cur_pos = 0;
		lst_item = *a;
		smallest_item = lst_item;
		while (lst_item)
		{
			if (lst_item->content < smallest_item->content)
			{
				smallest_item = lst_item;
				smallest_pos = cur_pos;
			}
			lst_item = lst_item->next;
			cur_pos++;
		}
		if (ft_lstsize(*a) - smallest_pos >= smallest_pos)
			rot_ptr = &rotate_a;
		else
		{
			rot_ptr = &reverse_rotate_a;
			smallest_pos = ft_lstsize(*a) - smallest_pos;
		}
		while (smallest_pos > 0)
		{
			(*rot_ptr)(a);
			smallest_pos--;
		}
		push_b(a, b);
	}
	while (ft_lstsize(*b))
	{
		push_a(a, b);
	}
}
