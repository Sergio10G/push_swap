/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:08:43 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/08 12:57:14 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*input;

	a = 0;
	b = 0;
	input = 0;
	if (argc < 2)
		exit(0);
	parse_nums(argc, argv, &a);
	read_input(&input);
	normalize_list(a);
	if (input)
	{
		follow_instructions(&a, &b, input);
		free(input);
	}
	if (ft_lstsize(b) == 0 && lst_is_ordered(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstclear(&a);
}

void	read_input(char **input)
{
	char	tmp_buf[CHK_BUF_SIZE + 1];
	int		i;

	i = -1;
	while (i != 0)
	{
		i = read(0, tmp_buf, CHK_BUF_SIZE);
		tmp_buf[i] = 0;
		if (i == 0)
			break ;
		if (!(*input))
			*input = ft_strdup(tmp_buf);
		else
			concat_strs(tmp_buf, i, input);
	}
}

void	follow_instructions(t_list **a, t_list **b, char *input)
{
	char	**insts;
	int		i;

	if (input[ft_strlen(input) - 1] != '\n')
		error_free_chk(a, b, input);
	insts = ft_split(input, '\n');
	i = 0;
	while (insts[i])
	{
		make_move(input, insts[i], a, b);
		free(insts[i]);
		i++;
	}
	free(insts);
}

void	make_move(char *input, char *movement, t_list **a, t_list **b)
{
	if (check_move(movement, "sa"))
		swap_a(a);
	else if (check_move(movement, "sb"))
		swap_b(b);
	else if (check_move(movement, "ss"))
		swap_ab(a, b);
	else if (check_move(movement, "pa"))
		push_a(a, b);
	else if (check_move(movement, "pb"))
		push_b(a, b);
	else if (check_move(movement, "ra"))
		rotate_a(a);
	else if (check_move(movement, "rb"))
		rotate_b(b);
	else if (check_move(movement, "rr"))
		rotate_ab(a, b);
	else if (check_move(movement, "rra"))
		reverse_rotate_a(a);
	else if (check_move(movement, "rrb"))
		reverse_rotate_b(b);
	else if (check_move(movement, "rrr"))
		reverse_rotate_ab(a, b);
	else
		error_free_chk(a, b, input);
}
