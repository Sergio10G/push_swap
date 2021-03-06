/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:08:36 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/03 17:15:08 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	error_quiet(void)
{
	exit(1);
}
