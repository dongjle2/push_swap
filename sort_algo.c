/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:39:33 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/10 02:54:58 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_input *i, t_input *j)
{
	t_input	tmp;

	if (i->nums == j->nums)
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

size_t	partition(t_input *arr, size_t l, size_t h)
{
	size_t	idx_i;
	size_t	idx_j;
	int		pivot;

	idx_i = l;
	idx_j = h;
	pivot = arr[idx_i].nums;
	while (idx_i < idx_j)
	{
		while ((idx_i < h) && (arr[idx_i].nums <= pivot))
			idx_i++;
		while ((l < idx_j) && (pivot < arr[idx_j].nums))
			idx_j--;
		if (idx_i < idx_j)
			swap(&arr[idx_j], &arr[idx_i]);
	}
	swap(&arr[l], &arr[idx_j]);
	return (idx_i);
}

void	quick_sort(t_input *arr, size_t l, size_t h)
{
	size_t	j;

	if (l < h)
	{
		j = partition(arr, l, h);
		quick_sort(arr, l, j - 1);
		quick_sort(arr, j, h);
	}
}

void	clear_stack_b(t_both_stacks *x)
{
	while (x->a.size--)
		pa(x, x->mode);
}

void	radix_sort(int len, t_both_stacks *x, int cur_bit)
{
	t_bit_ops	ops;
	t_stack		*cur_stack;

	if (len == cur_bit)
	{
		if (len % 2 == 1)
			clear_stack_b(x);
		return ;
	}
	if (x->b.top == -1)
	{
		cur_stack = &x->a;
		cur_stack->arr = x->a.arr;
		set_ops('a', &ops);
	}
	else
	{
		cur_stack = &x->b;
		cur_stack->arr = x->b.arr;
		set_ops('b', &ops);
	}
	clear_stack(x, cur_stack, ops, cur_bit);
	radix_sort(len, x, cur_bit + 1);
	return ;
}
