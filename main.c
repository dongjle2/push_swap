#include <string.h>
#include "push_swap.h"

void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_darr *mallocs, t_stack *a);
int		get_ternary_len(int num);
void	normalize_2(t_both_stacks *x, t_both_stacks *fake);

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

void	init_malloc_darr(t_darr *mallocs)
{
	mallocs->capacity = 128;
	mallocs->size = 0;
	mallocs->arr = ft_calloc(mallocs->capacity, sizeof(void *));
	if (mallocs->arr == NULL)
		exit(-1);
}

void	setup_stacks(char *argv[], t_darr *mallocs, t_both_stacks *stacks, t_both_stacks *fake_stacks)
{
	char	**whole_split;
	int		*int_arr;
	size_t	len_arr;

	whole_split =  get_whole_split(argv);
	len_arr = split_len(whole_split);
	int_arr = str_arr_to_int_arr(whole_split, len_arr);
	if ((validate_input(whole_split, int_arr, len_arr) == 1) ||\
		(is_sorted(int_arr, len_arr) == 1))
		{
			free_split(whole_split);
			free(int_arr);
			exit (1);
		}
	init_malloc_darr(mallocs);
	init_stacks(mallocs, stacks, len_arr);
	init_stacks(mallocs, fake_stacks, stacks->a.size);
	fill_up_a(&stacks->a, int_arr, stacks->a.size);
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
		return (0);
	}
	ft_memcpy(fake_stacks.a.arr, stacks.a.arr, sizeof(int) * (stacks.a.size));
	ft_memcpy(fake_stacks.b.arr, stacks.b.arr, sizeof(int) * (stacks.a.size));
	radix_sort(get_ternary_len(stacks.a.size), &fake_stacks, 0);
	normalize_2(&stacks, &fake_stacks);
	stacks.mode = 1;
	radix_sort(get_ternary_len(stacks.a.size), &stacks, 0);
	free_mallocs(&mallocs);
	return (0);
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

void	normalize_2(t_both_stacks *x, t_both_stacks *fake)
{
	t_stack		*cur;
	t_stack		*fake_cur;
	int			*n;

	if (x->a.top == -1)
	{
		cur = &x->b;
		fake_cur = &fake->b;
	}
	else if (x->b.top == -1)
	{
		cur = &x->a;
		fake_cur = &fake->a;
	}
	n = ft_calloc(x->a.size, sizeof(int));
	for (size_t i = 0; i < cur->size; i++)
	{
		size_t j = 0;
		for (size_t k = 0; k < cur->size; k++)
		{
			if (cur->arr[k] == i)
				j = k;
		}
		n[j] = fake_cur->arr[cur->size - i - 1];
	}
	ft_memcpy(cur->arr, n, sizeof(int) * x->a.size);
	free(n);
}

int	get_ternary_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 3;
		len++;
	}
	return (len);
}

void	set_ops(char stack, t_bit_ops *ops)
{
	if (stack == 'a')
	{
		ops->bit_0 = &pb;
		ops->bit_1[0] = &pb;
		ops->bit_1[1] = &rb;
		ops->bit_2[0] = &ra;
		ops->bit_2[1] = &pb;
	}
	else
	{
		ops->bit_0 = &pa;
		ops->bit_1[0] = &pa;
		ops->bit_1[1] = &ra;
		ops->bit_2[0] = &rb;
		ops->bit_2[1] = &pa;
	}
	return ;
}

void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit)
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

void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit)
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
