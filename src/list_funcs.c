/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:44 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/31 20:13:02 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
	t_list	*cur_lst;
	int		min;
	int		min_idx;
	int		i;

	cur_lst = *a;
	min = (*a)->content;
	min_idx = 0;
	cur_lst = cur_lst->next;
	i = 1;
	while (cur_lst)
	{
		if (cur_lst->content < min)
		{
			min = cur_lst->content;
			min_idx = i;
		}
		i++;
		cur_lst = cur_lst->next;
	}
	return (min_idx);
}

void	rotate_min_to_top(t_list **a)
{
	int		min_idx;
	void	(*rot_ptr)(t_list **);

	if (ft_lstsize(*a) < 2)
		return ;
	min_idx = get_min_index(a);
	if (min_idx <= ft_lstsize(*a) / 2)
		rot_ptr = &rotate_a;
	else
	{
		rot_ptr = &reverse_rotate_a;
		min_idx = ft_lstsize(*a) - min_idx;
	}
	while (min_idx != 0)
	{
		(*rot_ptr)(a);
		min_idx--;
	}
}
