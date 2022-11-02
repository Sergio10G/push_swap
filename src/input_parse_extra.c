/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:32:17 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/11/02 12:50:01 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	num_in_int_range(t_list **a, char *num_str)
{
	if (ft_strlen(num_str) > 11 || \
		(ft_strlen(num_str) >= 10 && \
		(ft_atoi(num_str) == 0 || ft_atoi(num_str) == -1)))
	{
		error_free(a);
	}
}
