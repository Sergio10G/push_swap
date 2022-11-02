/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:57:16 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/02 12:51:04 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_nums(int argc, char **argv, t_list **a)
{
	int		i;
	int		j;
	char	**nums;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			error_free(a);
		j = 0;
		while (nums[j])
		{
			num_in_int_range(a, nums[j]);
			process_num(ft_atoi(nums[j]), nums, j, a);
			j++;
		}
		free_matrix(nums);
		if (j == 0)
			error_free(a);
		i++;
	}
	check_order_rpt(a);
	return (ft_lstsize(*a));
}

void	process_num(int num, char **nums, int num_index, t_list **a)
{
	if (num == 0 && !str_is_zero(nums[num_index]))
	{
		free_matrix(nums);
		error_free(a);
	}
	ft_lstadd_back(a, ft_lstnew(num));
}

void	check_order_rpt(t_list **a)
{
	t_list	*lst;

	lst = *a;
	while (lst && lst->next != 0)
	{
		if (ft_lst_contains(lst->next, lst->content))
			error_free(a);
		lst = lst->next;
	}
	lst = *a;
	while (lst && lst->next != 0)
	{
		if (lst->content > lst->next->content)
			return ;
		lst = lst->next;
	}
	exit(0);
}

void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	str_is_zero(char *num)
{
	if (ft_strncmp(num, "0", 1) == 0 && ft_strlen(num) == 1)
		return (1);
	return (0);
}
