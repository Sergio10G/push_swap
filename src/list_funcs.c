/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:44 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/09 19:49:03 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lst_contains(t_list *head, int n)
{
	while (head != 0)
	{
		if (head->content == n)
			return (1);
		head = head->next;
	}
	return (0);
}

int	lst_is_ordered(t_list **lst)
{
	t_list	*item;
	int		prev_num;

	if (ft_lstsize(*lst) < 2)
		return (1);
	prev_num = (*lst)->content;
	item = (*lst)->next;
	while (item)
	{
		if (prev_num > item->content)
			return (0);
		prev_num = item->content;
		item = item->next;
	}
	return (1);
}

int	get_min_index(t_list **a)
{
	t_list	*item;
	int		min_idx;
	int		min;
	int		i;

	if (ft_asize(*a) < 2)
		return ;
	item = (*a)->next;
	min_idx = 0;
	min = (*a)->content;
	i = 0;
	while (item)
	{
		if (item->content < min)
		{
			min = item->content;
			min_idx = i;
		}
		item = item->next;
		i++;
	}
	return (min_idx);
}

void	rotate_min_to_top(t_list **a)
{
	int		min_idx;
	void	(*rotate_ptr)(t_list **);

	if (ft_asize(*a) < 2)
		return ;
	min_idx = get_min_index(a);
	if (min_idx <= ft_asize(*a) - min_idx)
		rot_ptr = &rotate_a;
	else
	{
		rot_ptr = &reverse_rotate_a;
		min_idx = ft_lstsize(*lst) - min_idx;
	}
	while (min_idx != 0)
	{
		(*rot_ptr)(lst);
		min_idx--;
	}
}
