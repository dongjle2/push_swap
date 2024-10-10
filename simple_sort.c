/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:30:29 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/10 03:15:45 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_both_stacks *stacks)
{
	if (stacks->a.top < 3)
	{
		if (stacks->a.top == 2)
			sort_3_elem(stacks);
		else
			ra(stacks, 1);
		return ;
	}
	else
	{
		max_on_top(stacks);
		pb(stacks, 1);
		simple_sort(stacks);
		pa(stacks, 1);
		ra(stacks, 1);
	}
}

void	max_on_top(t_both_stacks *stacks)
{
	int	idx;

	idx = get_max_idx(stacks->a);
	if (idx == stacks->a.top)
		return ;
	if (stacks->a.top - idx <= idx)
	{
		while (idx < stacks->a.top)
		{
			ra(stacks, 1);
			idx++;
		}
	}
	else
	{
		while (0 <= idx)
		{
			rra(stacks, 1);
			idx--;
		}
	}
}

int	get_max_idx(t_stack a)
{
	int				i;
	unsigned int	max;
	int				max_idx;

	i = 1;
	max = a.arr[0];
	max_idx = 0;
	while (i <= a.top)
	{
		if (max < a.arr[i])
		{
			max = a.arr[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

void	sort_3_elem(t_both_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->a.arr[0];
	b = stacks->a.arr[1];
	c = stacks->a.arr[2];
	if (c < b && b < a)
		return ;
	if (a < c && c < b)
		rra(stacks, 1);
	else if (b < c && c < a)
		sa(stacks, 1);
	else if (a < b && b < c)
	{
		ra(stacks, 1);
		sa(stacks, 1);
	}
	else if (b < a && a < c)
		ra(stacks, 1);
	else
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
}
