/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:08 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:09:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

int		parse_input(int ac, char **av, t_stacks *stacks);
int		create_stacks(t_stacks *stacks);
int		create_arrays(t_stacks *stacks, int size);
void	delete_arrays(t_stacks *stacks);
void	delete_stacks(t_stacks *stacks);

void	sort(t_stacks *stacks);
void	small_sort(t_stacks *stacks);
int		check_dupes(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
int		flatten_stack(t_stacks *stacks);

#endif
