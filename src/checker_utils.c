/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:56:19 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/03 19:18:06 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_move(char *input_move, char *correct_move)
{
	int	len;

	len = ft_strlen(correct_move);
	if ((int) ft_strlen(input_move) != len)
		return (0);
	return (ft_strncmp(input_move, correct_move, len) == 0);
}
