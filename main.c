#include "push_swap.h"

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_stack *a);
int		get_ternary_len(long long num);

int	main(int argc, char *argv[])
{
	t_both_stacks stacks;
	t_cnt_instructions	c;

	init_stacks(&stacks, argc - 1);
	fill_up_a(&stacks.a, argc - 1, argv);
	for (int i = 0; i < argc - 1; i ++)
	{
		printf("%d ", stacks.a.arr[i]);
	}
	printf("\n");
	normalize(&stacks.a);
	for (int i = 0; i < argc - 1; i ++)
	{
		printf("%d ", stacks.a.arr[i]);
	}
	printf("\n");
	//	// simple_sort(&a, &b, &c);
	radix_sort(get_ternary_len(argc - 1), &stacks, 0);
	// printf("%d %d %d %d %d %d %d %d\n", stacks.a.arr[0], stacks.a.arr[1], stacks.a.arr[2], stacks.a.arr[3], stacks.a.arr[4], stacks.a.arr[5], stacks.a.arr[6], stacks.a.arr[7]);
	for (int i = 0; i < argc - 1; i ++)
	{
		printf("%d ", stacks.b.arr[i]);
	}
	printf("\n");	// free(a.arr);
	// free(b.arr);
	// free(t.tmp_a.arr);
	// free(t.tmp_b.arr);
	return (0);
}

void	normalize(t_stack *a)
{
	t_input 	*x;
	int			i;
	long long	*ranks;

	x = ft_calloc(a->size, sizeof(t_input));
	ranks = ft_calloc(a->size, sizeof(long long));
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
	i = -1;
	// for (int i = 0; i < a->size; i++)
	// 	printf("%lld ", ranks[i]);
	// printf("\n");
	while (++i < a->size)
		a->arr[i] = ranks[i];
	free(x);
	free(ranks);
}

int	get_ternary_len(long long num)
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
		ops->bit_0 = &ra;
		ops->bit_2[0] = &pb;
		ops->bit_2[1] = &rb;
		ops->bit_1 = &pb;
	}
	else
	{
		ops->bit_0 = &rb;
		ops->bit_2[0] = &pa;
		ops->bit_2[1] = &ra;
		ops->bit_1 = &pa;
	}
	return ;
}

void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit)
{
	int	cnt;

	cnt = 0;
	// printf("clear_stack, cur_bit %d\n", cur_bit);
	while (cnt++ < cur_stack->size)
	{
		exec_ops(x, cur_stack, ops, cur_bit);
	}
	while (-1 < cur_stack->top)
	{
		ops.bit_1(&x->a, &x->b);
		// printf("aa\n");
	}
}

void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit)
{
	int	tmp;
	int	cnt_bit;

	tmp = cur_stack->arr[cur_stack->top];
	cnt_bit = cur_bit;
	while (cnt_bit--)
		tmp /= 3;
	// printf("cur_bit, top %d ,%d\n", cur_bit, cur_stack->arr[cur_stack->top]);
	if (tmp % 3 == 0)
	{
		ops.bit_0(&x->a, &x->b);
		// ops.bit_0[1](&x->a, &x->b);
	}
	else if (tmp % 3 == 1)
	{
		ops.bit_1(&x->a, &x->b);
		// ops.bit_1[1](&x->a, &x->b);
	}
	else
	{
		ops.bit_2[0](&x->a, &x->b);
		ops.bit_2[1](&x->a, &x->b);
	}
	return ;
}

void	radix_sort(int len, t_both_stacks *x, int cur_bit)
{
	t_bit_ops 	ops;
	t_stack		*cur_stack;

	if (len == cur_bit)
		return ;
	if (cur_bit % 2 == 0)
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
	// printf("%d %d %d %d %d %d %d %d\n", x->a.arr[0], x->a.arr[1], x->a.arr[2], x->a.arr[3], x->a.arr[4], x->a.arr[5], x->a.arr[6], x->a.arr[7]);
	// printf("%d %d %d %d %d %d %d %d\n", x->b.arr[0], x->b.arr[1], x->b.arr[2], x->b.arr[3], x->b.arr[4], x->b.arr[5], x->b.arr[6], x->b.arr[7]);
	radix_sort(len, x, cur_bit + 1);
	return ;
}
