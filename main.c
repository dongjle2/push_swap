/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:37:27 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/10 14:57:54 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_both_stacks	stacks;
	t_both_stacks	fake_stacks;
	t_darr			mallocs;

	(void)argc;
	setup_stacks(argv, &mallocs, &stacks, &fake_stacks);
	normalize(&mallocs, &stacks.a);
	if (stacks.a.size < 6)
	{
		simple_sort(&stacks);
		free_mallocs(&mallocs);
		return (0);
	}
	ft_memcpy(fake_stacks.a.arr, stacks.a.arr, sizeof(int) * (stacks.a.size));
	ft_memcpy(fake_stacks.b.arr, stacks.b.arr, sizeof(int) * (stacks.a.size));
	radix_sort(get_ternary_len(stacks.a.size), &fake_stacks, 0);
	normalize_2(&mallocs, &stacks, &fake_stacks);
	stacks.mode = 1;
	radix_sort(get_ternary_len(stacks.a.size), &stacks, 0);
	free_mallocs(&mallocs);
	return (0);
}

void	setup_stacks(char *argv[], \
	t_darr *mallocs, t_both_stacks *stacks, t_both_stacks *fake_stacks)
{
	char	**whole_split;
	int		*int_arr;
	size_t	len_arr;

	whole_split = get_whole_split(argv);
	len_arr = split_len(whole_split);
	int_arr = str_arr_to_int_arr(whole_split, len_arr);
	if ((validate_input(whole_split, int_arr, len_arr) == 1) || \
		(is_sorted(int_arr, len_arr) == 1))
	{
		free_split(whole_split);
		free(int_arr);
		exit (0);
	}
	free_split(whole_split);
	init_malloc_darr(mallocs);
	init_stacks(mallocs, stacks, len_arr);
	init_stacks(mallocs, fake_stacks, stacks->a.size);
	fill_up_a(&stacks->a, int_arr, stacks->a.size);
	free(int_arr);
}

void	normalize(t_darr *mallocs, t_stack *a)
{
	t_input	*x;
	size_t	i;
	int		*ranks;

	x = ft_manage_calloc(a->size, sizeof(t_input), mallocs);
	if (x == NULL)
		malloc_fails(mallocs);
	ranks = ft_manage_calloc(a->size, sizeof(int), mallocs);
	if (ranks == NULL)
		malloc_fails(mallocs);
	i = 0;
	while (i < a->size)
	{
		x[i].nums = a->arr[i];
		x[i].idx = i;
		i++;
	}
	quick_sort(x, 0, a->size - 1);
	i = 0;
	while (i < a->size)
	{
		ranks[x[i].idx] = i;
		i++;
	}
	ft_memcpy(a->arr, ranks, sizeof(int) * a->size);
}

void	change_value(t_stack *cur, t_stack *fake_stack, unsigned int *tmp)
{
	unsigned int	i;
	size_t			j;
	size_t			k;

	i = 0;
	while (i < cur->size)
	{
		j = 0;
		k = 0;
		while (k < cur->size)
		{
			if (cur->arr[k] == i)
				j = k;
			k++;
		}
		tmp[j] = fake_stack->arr[cur->size - i - 1];
		i++;
	}
}

void	normalize_2(t_darr *mallocs, t_both_stacks *s, t_both_stacks *fake)
{
	t_stack			*cur;
	t_stack			*fake_cur;
	unsigned int	*tmp;

	set_cur_stack(s, fake);
	cur = s->cur_stack;
	fake_cur = fake->cur_stack;
	tmp = ft_calloc(s->a.size, sizeof(int));
	tmp = ft_manage_calloc(s->a.size, sizeof(int), mallocs);
	if (tmp == NULL)
		malloc_fails(mallocs);
	change_value(cur, fake_cur, tmp);
	ft_memcpy(cur->arr, tmp, sizeof(int) * s->a.size);
}

// void	normalize_2(t_darr *mallocs, t_both_stacks *x, t_both_stacks *fake)
// {
// 	t_stack		*cur;
// 	t_stack		*fake_cur;
// 	int			*tmp;

// 	if (x->a.top == -1)
// 	{
// 		cur = &x->b;
// 		fake_cur = &fake->b;
// 	}
// 	else
// 	{
// 		cur = &x->a;
// 		fake_cur = &fake->a;
// 	}
// 	tmp = ft_manage_calloc(x->a.size, sizeof(int), mallocs);
// 	if (tmp == NULL)
// 		malloc_fails(mallocs);
// 	for (size_t i = 0; i < cur->size; i++)
// 	{
// 		size_t j = 0;
// 		for (size_t k = 0; k < cur->size; k++)
// 		{
// 			if (cur->arr[k] == i)
// 				j = k;
// 		}
// 		tmp[j] = fake_cur->arr[cur->size - i - 1];
// 	}
// 	ft_memcpy(cur->arr, tmp, sizeof(int) * x->a.size);
// }
