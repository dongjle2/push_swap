/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:54:37 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/09 00:21:29 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_darr *mallocs, t_both_stacks *x, size_t sz)
{
	x->a.arr = ft_manage_calloc(sz, sizeof(int), mallocs);
	if (x->a.arr == NULL)
		malloc_fails(mallocs);
	x->b.arr = ft_manage_calloc(sz, sizeof(int), mallocs);
	if (x->b.arr == NULL)
		malloc_fails(mallocs);
	x->a.top = sz - 1;
	x->a.size = sz;
	x->b.top = -1;
	x->b.size = sz;
	x->mode = 0;
	x->cur_stack = &x->a;
}

// void	add_inst(t_inst_darr *c, const char *instr)
// {
// 	char	**tmp_arr;
// 	int		i;

// 	i = 0;
// 	if (c->capacity == c->size)
// 	{
// 		c->capacity *= 2;
// 		tmp_arr = ft_calloc(c->capacity, sizeof(char *));
// 		while (i < c->capacity / 2)
// 		{
// 			tmp_arr[i] = c->arr[i];
// 			i++;
// 		}
// 		free(c->arr);
// 		c->arr = NULL;
// 		c->arr = tmp_arr;
// 	}
// 	c->arr[c->size] = (char *)instr;
// 	c->size++;
// }

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

void	free_mallocs(t_darr *mallocs)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		// printf("%zu\n", i);
		if (mallocs->arr[i])
		{
			free(mallocs->arr[i]);
			mallocs->arr[i] = NULL;
		}
		i++;
	}
	free(mallocs->arr);
}

// static char	is_sorted(t_stack *x, char id)
// {
// 	int	up;
// 	int	down;

// 	up = 1;
// 	down = 0;
// 	while (up <= x->top)
// 	{
// 		if (id == 'a')
// 		{
// 			if (x->arr[down] - x->arr[up] <= 0)
// 				return (-1);
// 		}
// 		else
// 		{
// 			if (x->arr[up] - x->arr[down] <= 0)
// 				return (-1);
// 		}
// 		up++;
// 		down++;
// 	}
// 	return (0);
// }
