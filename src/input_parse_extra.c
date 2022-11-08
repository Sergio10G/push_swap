/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:32:17 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/08 12:27:08 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	num_in_int_range(char *num_str)
{
	return (!(ft_strlen(num_str) > 11 || \
		(ft_strlen(num_str) >= 10 && \
		(ft_atoi(num_str) == 0 || ft_atoi(num_str) == -1))));
}

int	is_all_numeric(char *num_str)
{
	int	i;

	i = 0;
	while (num_str[i])
	{
		if (num_str[i] != '-' && !ft_isdigit(num_str[i]))
			return (0);
		i++;
	}
	return (1);
}
