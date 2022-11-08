/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:35:16 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/08 12:32:13 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		exit(0);
	a = 0;
	b = 0;
	parse_nums(argc, argv, &a);
	if (lst_is_ordered(a))
	{
		ft_lstclear(&a);
		exit(0);
	}
	normalize_list(a);
	arrange(&a, &b);
	ft_lstclear(&a);
}
