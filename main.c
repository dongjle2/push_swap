#include "push_swap.h"

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_stack *a);
int		get_ternary_len(long long num);
void	normalize_2(t_both_stacks *x, t_norm2 *n);

void	push_a(t_both_stacks *x)
{
	if (x->a.top != 0)
		return ;
	while (-1 < x->a.top)
		pa(&x->a, &x->b, x->mode);
}

int	main(int argc, char *argv[])
{
	t_both_stacks stacks;
	t_cnt_instructions	c;
	t_norm2	*n;

	init_stacks(&stacks, argc - 1);
	fill_up_a(&stacks.a, argc - 1, argv);
	normalize(&stacks.a);
	// printf("1 a arr");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	printf("%lld ", stacks.a.arr[i]);
	// }
	// printf("\n");
	// long long	*tmp;
	// tmp = ft_calloc(stacks.a.size, sizeof(long long));
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	tmp[i] = stacks.a.arr[i];
	// }
	n = ft_calloc(stacks.a.size, sizeof(t_norm2));
	for (int i = 0; i < argc - 1; i ++)
	{
		n[i].real = stacks.a.arr[i];
	}
	radix_sort(get_ternary_len(argc - 1), &stacks, 0);
	push_a(&stacks);
	// printf("b arr");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	printf("%lld ", stacks.b.arr[i]);
	// }
	// printf("\n");
	normalize_2(&stacks, n);
	stacks.mode = 1;
	radix_sort(get_ternary_len(argc - 1), &stacks, 0);
	push_a(&stacks);
	// printf("b arr");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	printf("%lld ", stacks.b.arr[i]);
	// }
	// printf("\n");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	for (int j = 0; j < argc - 1; j++)
	// 	{
	// 		if (stacks.b.arr[i] == n[j].fake)
	// 			printf("%lld ", n[j].real);
	// 	}
	// }
	// printf("\n");
	// printf("\n");
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
		ranks[x[i].idx] = i;	//
	i = -1;
	// printf("ranks\n");
	// for (int i = 0; i < a->size; i++)
	// 	printf("%lld ", ranks[i]);
	// printf("\n");
	while (++i < a->size)
		a->arr[i] = ranks[i];
	free(x);
	free(ranks);
}

void	normalize_2(t_both_stacks *x, t_norm2 *n)
{
	int			i;
	int			j;
	t_stack		*cur;

	if (x->a.top == -1)
		cur = &x->b;
	else
		cur = &x->a;
	i = 0;
	while (i < x->a.size)
	{
		j = 0;
		while (j < x->a.size)
		{
			if (i == n[j].real)
				n[j].fake = cur->arr[i];
			j++;
		}
		i++;
	}
	// printf("original \n");
	// for (int i = 0; i < x->a.size; i ++)
	// {
	// 	printf("%lld ", n[i].real);
	// }
	// printf("\n");
	// printf("fake \n");
	// for (int i = 0; i < x->a.size; i ++)
	// {
	// 	printf("%lld ", n[i].fake);
	// }
	// printf("\n");
	// i = -1;
	// while (++i < x->a.size)
	// 	cur->arr[i] = n[i].fake;
	// printf("arr \n");
	// for (int i = 0; i < x->a.size; i ++)
	// {
	// 	printf("%lld ", cur->arr[i]);
	// }
	// printf("\n");
	// while (++i < a->size)
	// 	tmp[i] = order[i];
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
	// printf("cur_bit, top %d ,%d\n", cur_bit, cur_stack->arr[cur_stack->top]);
	if (tmp % 3 == 0)
	{
		ops.bit_0(&x->a, &x->b, x->mode);
	}
	else if (tmp % 3 == 1)
	{
		ops.bit_1[0](&x->a, &x->b, x->mode);
		ops.bit_1[1](&x->a, &x->b, x->mode);
	}
	else
	{
		ops.bit_2[0](&x->a, &x->b, x->mode);
		// ops.bit_2[1](&x->a, &x->b);
	}
	return ;
}

void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit)
{
	int	cnt;
	int	i;

	cnt = 0;
	// printf("clear_stack, cur_bit %d\n", cur_bit);
	while (cnt++ < cur_stack->size)
	{
		exec_ops(x, cur_stack, ops, cur_bit);
	}
	while (-1 < cur_stack->top)
	{
		ops.bit_2[1](&x->a, &x->b, x->mode);
	}
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
	// printf("in \n");
	// if (cur_bit % 2 == 0)
	// {
	// 	for (int i = 0; i < x->b.size; i ++)
	// 	{
	// 		printf("%d ", x->b.arr[i]);
	// 	}
	// }
	// else
	// {
	// 	for (int i = 0; i < x->b.size; i ++)
	// 	{
	// 		printf("%d ", x->a.arr[i]);
	// 	}
	// }
	// printf("\n");
	radix_sort(len, x, cur_bit + 1);
	return ;
}
