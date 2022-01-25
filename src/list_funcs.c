/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:44 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/25 20:40:08 by sdiez-ga         ###   ########.fr       */
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
