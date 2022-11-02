/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:08:43 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/02 14:42:41 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*input;

	if (argc < 2)
		exit(0);
	input = 0;
	read_input(&input);
	parse_nums(argc, argv, &a);
	normalize_list(a);
	follow_instructions(&a, &b, input);
	if (ft_lstsize(b) == 0 && lst_is_ordered(&a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstclear(&a);
}

void	read_input(char **input)
{
	char	tmp_buf[CHK_BUF_SIZE];
	int		i;

	i = -1;
	while (i != 0)
	{
		ft_bzero(tmp_buf, CHK_BUF_SIZE);
		i = read(0, tmp_buf, CHK_BUF_SIZE - 1);
		if (!(*input))
			*input = ft_strdup(tmp_buf);
		else
			concat_strs(tmp_buf, input);
	}
}

void	concat_strs(const char *s1, char **s2)
{
	char	*out;
	int		len_1;
	int		i_1;
	int		len_2;
	int		i_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(*s2);
	if (!len_1 || !len_2)
		return ;
	out = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!out)
		return ;
	i_2 = -1;
	while ((*s2)[++i_2])
		out[i_2] = (*s2)[i_2];
	i_1 = -1;
	while (s1[++i_1])
		out[i_1 + i_2] = s1[i_1];
	out[i_1 + i_2] = 0;
	free(*s2);
	*s2 = out;
}

void	follow_instructions(t_list **a, t_list **b, char *input)
{
	char	**insts;
	int		i;

	insts = ft_split(input, '\n');
	i = 0;
	while (insts[i])
	{
		recognize_movement(insts[i], a, b);
		i++;
	}
}

void	recognize_movement(char *movement, t_list **a, t_list **b)
{
	if (!ft_strncmp(movement, "sa", 2))
		swap_a(a);
	else if (!ft_strncmp(movement, "sb", 2))
		swap_b(b);
	else if (!ft_strncmp(movement, "ss", 2))
		swap_ab(a, b);
	else if (!ft_strncmp(movement, "pa", 2))
		push_a(a, b);
	else if (!ft_strncmp(movement, "pb", 2))
		push_b(a, b);
	else if (!ft_strncmp(movement, "ra", 3))
		rotate_a(a);
	else if (!ft_strncmp(movement, "rb", 3))
		rotate_b(b);
	else if (!ft_strncmp(movement, "rr", 3))
		rotate_ab(a, b);
	else if (!ft_strncmp(movement, "rra", 3))
		reverse_rotate_a(a);
	else if (!ft_strncmp(movement, "rrb", 3))
		reverse_rotate_b(b);
	else if (!ft_strncmp(movement, "rrr", 3))
		reverse_rotate_ab(a, b);
}
