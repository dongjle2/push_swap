/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:54:37 by dongjle2          #+#    #+#             */
/*   Updated: 2024/07/08 02:55:11 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_both_stacks *x, int size)
{
	x->a.arr = ft_calloc(size, sizeof(int));
	if (x->a.arr == NULL)
		exit(-1);
	x->b.arr = ft_calloc(size, sizeof(int));
	if (x->b.arr == NULL)
		exit (-1);
	x->a.top = size - 1;
	x->a.size = size;
	x->b.top = -1;
	x->b.size = size;
	x->mode = 0;
	x->cur_stack = &x->a;
	ft_bzero(&x->c, sizeof(x->c));
}

void	add_inst(t_inst_darr *c, const char *inst)
{
	char	**tmp_arr;
	int		i;

	i = 0;
	if (c->capacity == c->size)
	{
		c->capacity *= 2;
		tmp_arr = ft_calloc(c->capacity, sizeof(char *));
		while (i < c->capacity / 2)
		{
			tmp_arr[i] = c->arr[i];
			i++;
		}
		free(c->arr);
		c->arr = NULL;
		c->arr = tmp_arr;
	}
	c->arr[c->size] = (char *)inst;
	c->size++;
}

static	int	isspace(const int c);

long long	ft_my_atoi(const char *str)
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
	if (*str != 0)
	{
		return (LONG_MAX);
	}
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

// void	fill_up_a(t_stack *a, int size, char *argv[])
// {
// 	int			i;
// 	long long	l;

// 	i = 0;
// 	while ((i < size) && argv[i] != NULL)
// 	{
// 		l = ft_my_atoi(argv[i + 1]);
// 		if ((INT_MAX < l) || (l < INT_MIN))
// 		a->arr[a->top - i] = ft_my_atoi(argv[i + 1]);
// 		i++;
// 	}
// }

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

// int	check_special_cases_a(t_stack *a)
// {
// 	char id;

// 	id = 'a';
// 	if (a->top < 1)
// 		return (0);
// 	else if (is_sorted(a, id) == 0)
// 		return (0);
// 	else if (a->top == 2)
// 	{
// 		sort_three_elements_a(a);
// 		return (0);
// 	}
// 	return (-1);
// }

// int	check_special_cases_b(t_stack *a, t_stack *b)
// {
// 	char 	id;
// 	int		i;

// 	id = 'b';
// 	i = b->top;
// 	if (i <= 0)
// 	{
// 		pa(a, b);
// 		return (0);
// 	}
// 	else if (is_sorted(b, id) == 0)
// 	{
// 		while (-1 < i--)
// 			pa(a, b);
// 		return (0);
// 	}
// 	else if (b->top == 2)
// 	{
// 		sort_three_elements_b(b);
// 		while (-1 < i--)
// 			pa(a, b);
// 		return (0);
// 	}
// 	return (-1);
// }

// void	sort_three_elements_a(t_stack *x)
// {
// 	if (x->arr[2] < x->arr[0] && x->arr[0] < x->arr[1])
// 	{
// 		rra(x, 0);
// 		sa(x, 0);
// 	}
// 	else if (x->arr[1] < x->arr[2] && x->arr[2] < x->arr[0])
// 		sa(x, 0);
// 	else if (x->arr[0] < x->arr[2] && x->arr[2] < x->arr[1])
// 		rra(x, 0);
// 	else if (x->arr[1] < x->arr[0] && x->arr[0] < x->arr[2])
// 		ra(x, 0);
// 	else if (x->arr[0] < x->arr[1] && x->arr[1] < x->arr[2])
// 	{
// 		ra(x, 0);
// 		sa(x, 0);
// 	}
// }

// void	sort_three_elements_b(t_stack *x)
// {
// 	if (x->arr[2] < x->arr[0] && x->arr[0] < x->arr[1])
// 		ra(x, 0);
// 	else if (x->arr[1] < x->arr[2] && x->arr[2] < x->arr[0])
// 		rra(x, 0);
// 	else if (x->arr[0] < x->arr[2] && x->arr[2] < x->arr[1])
// 		sa(x, 0);
// 	else if (x->arr[1] < x->arr[0] && x->arr[0] < x->arr[2])
// 	{
// 		rra(x, 0);
// 		sa(x, 0);
// 	}
// 	else if (x->arr[2] < x->arr[1] && x->arr[1] < x->arr[0])
// 	{
// 		sa(x, 0);
// 		rra(x, 0);
// 	}
// }
