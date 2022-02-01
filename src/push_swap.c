/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:35:16 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/31 19:04:18 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//TEMPORAL
void	print_content(void *lst);

int	main(int argc, char **argv)
{
	t_list	*a;
	//t_list	*b;

	if (argc < 2)
		error();
	parse_nums(argc, argv, &a);
	//ft_putnbr_fd(parse_nums(argc, argv, &a), 1);
	//write(1, "\n", 1);
	void	(*print_content_ptr)(void *) = &print_content;
	ft_lstiter(a, print_content_ptr);
	swap_a(&a);
	write(1, "-\n", 2);
	ft_lstiter(a, print_content_ptr);
}

void	print_content(void *lst)
{
	t_list	*llst;

	llst = (t_list *)lst;
	ft_putnbr_fd(llst->content, 1);
	ft_putchar_fd('\n', 1);
}
