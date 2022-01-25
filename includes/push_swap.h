/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:57:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/25 20:26:55 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	Libraries
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

//	Functions
	/* input_parse.c functions */
int		parse_nums(int argc, char **argv, t_list **a);
int		str_is_zero(char *num);
void	free_matrix(char **mat);

	/* error_comp.c functions */
void	error();
#endif
