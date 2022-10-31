/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:13:02 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/31 20:06:51 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
}

void	normalize_list(t_list *lst)
{
	int		new_num;
	t_list	*lowest;

	new_num = 1;
	lowest = fetch_lowest_num(lst);
	while (lowest)
	{
		lowest->content = new_num;
		lowest->flag = 1;
		new_num++;
		lowest = fetch_lowest_num(lst);
	}
}

t_list	*fetch_lowest_num(t_list *lst)
{
	t_list	*lowest;
	t_list	*lst_cur;

	lst_cur = lst;
	lowest = lst;
	while (lst_cur)
	{
		if (!lst_cur->flag)
		{
			lowest = lst_cur;
			break ;
		}
		lst_cur = lst_cur->next;
	}
	if (lowest->flag)
		return (0);
	while (lst)
	{
		if (!lst->flag && lst != lowest && lst->content < lowest->content)
			lowest = lst;
		lst = lst->next;
	}
	return (lowest);
}

int	get_biggest_num(t_list *lst)
{
	int	max;

	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	get_laps(int max_num)
{
	int	laps;

	laps = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		laps++;
	}
	return (laps);
}
