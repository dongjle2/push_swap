#include <string.h>
#include "push_swap.h"

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_darr *mallocs, t_stack *a);
int		get_ternary_len(int num);
void	normalize_2(t_both_stacks *x, t_both_stacks *fake);

void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs)
{
	void	*mem;

	mem = ft_calloc(count, size);
	add_malloc(mallocs, mem);
	return (mem);
}

void	malloc_fails(t_darr *mallocs)
{
	free_mallocs(mallocs);
	exit(-1);
}

void	init_fake_stacks(t_darr *mallocs, t_both_stacks *x, int size)
{
	x->a.arr = ft_manage_calloc(size, sizeof(int), mallocs);
	if (x->a.arr == NULL)
		malloc_fails(mallocs);
	x->b.arr = ft_manage_calloc(size, sizeof(int), mallocs);
	if (x->b.arr == NULL)
		malloc_fails(mallocs);
	x->a.top = size - 1;
	x->a.size = size;
	x->b.top = -1;
	x->b.size = size;
	x->mode = 0;
	x->cur_stack = &x->a;
}

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

// void	init_inst_darr(t_darr *mallocs, t_both_stacks *stacks)
// {
// 	t_inst_darr *inst_darr;

// 	inst_darr = &stacks->inst;
// 	inst_darr->capacity = 128;
// 	inst_darr->arr = (char **)ft_manage_calloc(inst_darr->capacity, sizeof(char *), mallocs);
// 	if (inst_darr->arr == NULL)
// 		malloc_fails(mallocs);
// 	inst_darr->size = 0;
// }

void	init_malloc_darr(t_darr *mallocs)
{
	mallocs->capacity = 128;
	mallocs->size = 0;
	mallocs->arr = ft_calloc(mallocs->capacity, sizeof(void *));
	if (mallocs->arr == NULL)
		exit(-1);
}

int	ck_input_range(t_darr *mallocs, int argc, char *argv[], t_both_stacks *stacks)
{
	t_stack		*a;
	size_t		i;
	long long	tmp;

	a = &stacks->a;
	i = 1;
	while (i < argc)
	{
		tmp = ft_my_atoi(argv[i]);
		if ((INT_MAX < tmp) || (tmp < INT_MIN))
		{
			free_mallocs(mallocs);
			return (1);
		}
		a->arr[a->top - (i - 1)] = (int)tmp;
		i++;
	}
	return (0);
}

void	add_malloc(t_darr *c, void *mem)
{
	void	**tmp_arr;
	size_t	i;

	i = 0;
	if (c->capacity == c->size)
	{
		c->capacity *= 2;
		tmp_arr = ft_calloc(c->capacity, sizeof(void *));
		while (i < c->capacity / 2)
		{
			tmp_arr[i] = c->arr[i];
			i++;
		}
		free(c->arr);
		c->arr = NULL;
		c->arr = tmp_arr;
	}
	c->arr[c->size] = mem;
	c->size++;
}

int	main(int argc, char *argv[])
{
	t_both_stacks	stacks;
	t_both_stacks	fake_stacks;
	t_darr			mallocs;
	t_darr			*pmallocs;

	pmallocs = &mallocs;
	init_malloc_darr(pmallocs);
	validate_input();
	init_stacks(pmallocs, &stacks, argc - 1);
	if (ck_input_range(pmallocs, argc, argv, &stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_fake_stacks(pmallocs, &fake_stacks, argc - 1);
	normalize(pmallocs, &stacks.a);
	ft_memcpy(fake_stacks.a.arr, stacks.a.arr, sizeof(int) * (argc - 1));
	ft_memcpy(fake_stacks.b.arr, stacks.b.arr, sizeof(int) * (argc - 1));
	radix_sort(get_ternary_len(argc - 1), &fake_stacks, 0);
	normalize_2(&stacks, &fake_stacks);
	stacks.mode = 1;
	radix_sort(get_ternary_len(argc - 1), &stacks, 0);

	free_mallocs(pmallocs);
	return (0);
}

// int	find_dup(t_input *x, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len - 1)
// 	{
// 		if (x[i].nums == x[i + 1].nums)
// 			return (1);
// 	}
// 	return (0);
// }

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
	int			i;
	int			j;
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
	for (int i = 0; i < cur->size; i++)
	{
		int j = 0;
		for (int k = 0; k < cur->size; k++)
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
	int	cnt;
	int	i;

	cnt = -1;
	while (++cnt < cur_stack->size)
	{
		exec_ops(x, cur_stack, ops, cur_bit);
	}
	while (-1 < cur_stack->top)
	{
		ops.bit_2[1](x, x->mode);
	}
}

void	radix_sort(int len, t_both_stacks *x, int cur_bit)
{
	t_bit_ops 	ops;
	t_stack		*cur_stack;

	if (len == cur_bit)
	{
		if (len % 2 == 1)
		{
			while (x->a.size--)
				pa(x, x->mode);
		}
		return ;
	}
	if (x->b.top == -1)
	{
		cur_stack = &x->a;
		cur_stack->arr = x->a.arr;
		set_ops('a', &ops);
	}
	else if (x->a.top == -1)
	{
		cur_stack = &x->b;
		cur_stack->arr = x->b.arr;
		set_ops('b', &ops);
	}
	clear_stack(x, cur_stack, ops, cur_bit);
	radix_sort(len, x, cur_bit + 1);
	return ;
}
