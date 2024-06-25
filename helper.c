/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:54:37 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/24 21:56:03 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_both_stacks *x, int size)
{
	x->a.arr = ft_calloc(size, sizeof(long long));
	if (x->a.arr == NULL)
		exit(-1);
	x->b.arr = ft_calloc(size, sizeof(long long));
	if (x->b.arr == NULL)
		exit (-1);
	x->a.top = size - 1;
	x->a.size = size;
	x->b.top = -1;
	x->b.size = size;
}

// void	init_tmp(t_tmp_stacks *t, int size)
// {
// 	t->tmp_a.arr = ft_calloc(size, sizeof(int));
// 	if (t->tmp_a.arr == NULL)
// 		exit(-1);
// 	t->tmp_a.size = size;
// 	t->tmp_a.top = size - 1;
// 	t->tmp_b.arr = ft_calloc(size, sizeof(int));
// 	if (t->tmp_b.arr == NULL)
// 		exit(-1);
// 	t->tmp_b.size = size;
// 	t->tmp_b.top = -1;
// }

static	int	isspace(const int c);

int	ft_atoll(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - 48);
	return (sign * num);
}

static	int	isspace(const int c)
{
	const char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
	{
		if (c == *space++)
			return (1);
	}
	return (0);
}

void	fill_up_a(t_stack *a, int size, char *argv[])
{
	int	i;

	i = 0;
	while ((i < size) && argv[i] != NULL)
	{
		a->arr[a->top - i] = ft_atoll(argv[i + 1]);
		i++;
	}
}

char	is_sorted(t_stack *x, char id)
{
	int	up;
	int	down;

	up = 1;
	down = 0;
	while (up <= x->top)
	{
		if (id == 'a')
		{
			if (x->arr[down] - x->arr[up] <= 0)
				return (-1);
		}
		else
		{
			if (x->arr[up] - x->arr[down] <= 0)
				return (-1);
		}
		up++;
		down++;
	}
	return (0);
}

int	check_special_cases_a(t_stack *a)
{
	char id;

	id = 'a';
	if (a->top < 1)
		return (0);
	else if (is_sorted(a, id) == 0)
		return (0);
	else if (a->top == 2)
	{
		sort_three_elements_a(a);
		return (0);
	}
	return (-1);
}

int	check_special_cases_b(t_stack *a, t_stack *b)
{
	char 	id;
	int		i;

	id = 'b';
	i = b->top;
	if (i <= 0)
	{
		pa(a, b);
		return (0);
	}
	else if (is_sorted(b, id) == 0)
	{
		while (-1 < i--)
			pa(a, b);
		return (0);
	}
	else if (b->top == 2)
	{
		sort_three_elements_b(b);
		while (-1 < i--)
			pa(a, b);
		return (0);
	}
	return (-1);
}

void	sort_three_elements_a(t_stack *x)
{
	if (x->arr[2] < x->arr[0] && x->arr[0] < x->arr[1])
	{
		rra(x, 0);
		sa(x, 0);
	}
	else if (x->arr[1] < x->arr[2] && x->arr[2] < x->arr[0])
		sa(x, 0);
	else if (x->arr[0] < x->arr[2] && x->arr[2] < x->arr[1])
		rra(x, 0);
	else if (x->arr[1] < x->arr[0] && x->arr[0] < x->arr[2])
		ra(x, 0);
	else if (x->arr[0] < x->arr[1] && x->arr[1] < x->arr[2])
	{
		ra(x, 0);
		sa(x, 0);
	}
}

void	sort_three_elements_b(t_stack *x)
{
	if (x->arr[2] < x->arr[0] && x->arr[0] < x->arr[1])
		ra(x, 0);
	else if (x->arr[1] < x->arr[2] && x->arr[2] < x->arr[0])
		rra(x, 0);
	else if (x->arr[0] < x->arr[2] && x->arr[2] < x->arr[1])
		sa(x, 0);
	else if (x->arr[1] < x->arr[0] && x->arr[0] < x->arr[2])
	{
		rra(x, 0);
		sa(x, 0);
	}
	else if (x->arr[2] < x->arr[1] && x->arr[1] < x->arr[0])
	{
		sa(x, 0);
		rra(x, 0);
	}
}
