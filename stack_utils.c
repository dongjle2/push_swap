/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:57:16 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/10 02:27:17 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cur_stack(t_both_stacks *x, t_both_stacks *fake)
{
	if (x->a.top == -1)
	{
		x->cur_stack = &x->b;
		fake->cur_stack = &fake->b;
	}
	else
	{
		x->cur_stack = &x->a;
		fake->cur_stack = &fake->a;
	}
}

void	fill_up_a(t_stack *a, int *arr, size_t len_arr)
{
	size_t	i;

	i = 0;
	while (i < len_arr)
	{
		a->arr[i] = arr[len_arr - 1 - i];
		i++;
	}
}

void	exec_ops(t_both_stacks *x, t_stack *cur_stack, \
		t_bit_ops ops, int cur_bit)
{
	int	tmp;
	int	cnt_bit;

	tmp = cur_stack->arr[cur_stack->top];
	cnt_bit = cur_bit;
	while (cnt_bit--)
		tmp /= 3;
	if (tmp % 3 == 0)
	{
		ops.bit_0(x, x->mode);
	}
	else if (tmp % 3 == 1)
	{
		ops.bit_1[0](x, x->mode);
		ops.bit_1[1](x, x->mode);
	}
	else
	{
		ops.bit_2[0](x, x->mode);
	}
	return ;
}

void	clear_stack(t_both_stacks *x, t_stack *cur_stack, \
		t_bit_ops ops, int cur_bit)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < cur_stack->size)
	{
		exec_ops(x, cur_stack, ops, cur_bit);
		cnt++;
	}
	while (-1 < cur_stack->top)
	{
		ops.bit_2[1](x, x->mode);
	}
}
