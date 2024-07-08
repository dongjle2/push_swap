#include <string.h>
#include "push_swap.h"

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_stack *a);
int		get_ternary_len(int num);
void	normalize_2(t_both_stacks *x, t_both_stacks *fake);

void	init_fake_stacks(t_both_stacks *x, int size)
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

void	init_inst_darr(t_inst_darr *inst_darr)
{
	inst_darr->capacity = 128;
	inst_darr->arr = ft_calloc(inst_darr->capacity, sizeof(char *));
	inst_darr->size = 0;
}

int	validate_input(int argc, char *argv[], t_stack *a)
{
	int			i;
	long long	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_my_atoi(argv[i]);
		if ((INT_MAX < tmp) || (tmp < INT_MIN))
		{
			// free();
			return (1);
		}
		a->arr[a->top - (i - 1)] = (int)tmp;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_both_stacks	stacks;
	t_both_stacks	fake_stacks;

	init_stacks(&stacks, argc - 1);
	if (validate_input(argc, argv, &stacks.a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_fake_stacks(&fake_stacks, argc - 1);
	init_inst_darr(&stacks.c);
	normalize(&stacks.a);
	ft_memcpy(fake_stacks.a.arr, stacks.a.arr, sizeof(int) * (argc - 1));
	ft_memcpy(fake_stacks.b.arr, stacks.b.arr, sizeof(int) * (argc - 1));
	radix_sort(get_ternary_len(argc - 1), &fake_stacks, 0);
	normalize_2(&stacks, &fake_stacks);
	stacks.mode = 1;
	radix_sort(get_ternary_len(argc - 1), &stacks, 0);
	for (int i = 0; i < stacks.c.size; i++)
	{
		if (ft_strncmp("ra\n", stacks.c.arr[i], 2) == 0 && (ft_strncmp("rb\n", stacks.c.arr[i + 1], 2) == 0))
		{
			write(1, "rr\n", 3);
			i++;
		}
		else if (ft_strncmp("rb\n", stacks.c.arr[i], 2) == 0 && (ft_strncmp("ra\n", stacks.c.arr[i + 1], 2) == 0))
		{
			write(1, "rr\n", 3);
			i++;
		}
		else
			write(1, stacks.c.arr[i], 3);
	}

	// free(b.arr);
	// free(t.tmp_a.arr);
	// free(t.tmp_b.arr);
	return (0);
}

void	normalize(t_stack *a)
{
	t_input	*x;
	int		i;
	int		*ranks;

	x = ft_calloc(a->size, sizeof(t_input));
	ranks = ft_calloc(a->size, sizeof(int));
	i = 0;
	while (i < a->size)
	{
		x[i].nums = a->arr[i];
		x[i].idx = i;
		i++;
	}
	quick_sort(x, 0, a->size - 1);
	i = -1;
	while (++i < a->size)
		ranks[x[i].idx] = i;
	ft_memcpy(a->arr, ranks, sizeof(int) * a->size);
	free(x);
	free(ranks);
}

void	normalize_2(t_both_stacks *x, t_both_stacks *fake)
{
	int			i;
	int			j;
	t_stack		*cur;
	t_stack		*fake_cur;
	int	*n;

	if (x->a.top == -1)
	{
		cur = &x->b;
		fake_cur = &fake->b;
	}
	else
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
	ft_memcpy(cur->arr, n, sizeof(n) * x->a.size);
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
		ops.bit_0(&x->a, &x->b, &x->c,x->mode);
	}
	else if (tmp % 3 == 1)
	{
		ops.bit_1[0](&x->a, &x->b, &x->c,x->mode);
		ops.bit_1[1](&x->a, &x->b, &x->c,x->mode);
	}
	else
	{
		ops.bit_2[0](&x->a, &x->b, &x->c,x->mode);
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
		ops.bit_2[1](&x->a, &x->b, &x->c, x->mode);
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
				pa(&x->a, &x->b, &x->c, x->mode);
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
