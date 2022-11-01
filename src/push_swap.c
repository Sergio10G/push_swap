/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:35:16 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/31 20:13:04 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		exit(0);
	parse_nums(argc, argv, &a);
	normalize_list(a);
	arrange(&a, &b);
	ft_lstclear(&a);
}

void	print_content(void *lst)
{
	t_list	*llst;

	llst = (t_list *)lst;
	ft_putnbr_fd(llst->content, 1);
	ft_putchar_fd('\n', 1);
}
