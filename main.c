#include "push_swap.h"
#include <string.h>

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);
void	normalize(t_stack *a);
int		get_ternary_len(long long num);
void	normalize_2(t_both_stacks *x, t_both_stacks *fake, t_norm2 *n);

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
	t_both_stacks fake_stacks;
	t_cnt_instructions	c;
	t_norm2	*n;

	init_stacks(&stacks, argc - 1);
	fill_up_a(&stacks.a, argc - 1, argv);
	normalize(&stacks.a);
	// memcpy(&fake_stacks, &stacks, sizeof(stacks));
	fake_stacks.a.arr = (long long *)malloc(sizeof(long long) * 11);
	fake_stacks.b.arr = (long long *)malloc(sizeof(long long) * 11);
	memcpy(fake_stacks.a.arr, stacks.a.arr, sizeof(long long) * 11);
	memcpy(fake_stacks.b.arr, stacks.b.arr, sizeof(long long) * 11);
	// fake_stacks.a.arr = stacks.a.arr;
	// fake_stacks.b.arr = stacks.b.arr;
	// printf("1 a arr");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	printf("%lld ", stacks.a.arr[i]);
	// }
	// printf("\n");
	// n = ft_calloc(stacks.a.size, sizeof(t_norm2));
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	n[i].real = stacks.a.arr[i];
	// }
	// radix_sort(get_ternary_len(argc - 1), &stacks, 0);
	// push_a(&stacks);
	printf("b arr");
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%lld ", stacks.a.arr[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		fake_stacks.a.arr[i] = 0;
		fake_stacks.b.arr[i] = 0;
	}
	fake_stacks.a.top = -1;
	fake_stacks.b.top = -1;
	printf("%d\n", stacks.a.top);
	printf("%d\n", stacks.b.top);
	printf("b arr");
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%lld ", stacks.a.arr[i]);
	}
	printf("\n");
	// normalize_2(&stacks, &fake_stacks, n);
	// fake_stacks.mode = 1;
	// printf("norm2\n");
	// for (int i = 0; i < argc - 1; i ++)
	// {
	// 	printf("%lld ", fake_stacks.b.arr[i]);
	// }
	// printf("\n");
	// radix_sort(get_ternary_len(argc - 1), &fake_stacks, 0);
	// push_a(&fake_stacks);
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
	// for (int i = 0; i < a->size; i++)
	// 	printf("%lld ", ranks[i]);
	// printf("\n");
	i = -1;
	while (++i < a->size)
		a->arr[i] = ranks[i];
	free(x);
	free(ranks);
}

void	normalize_2(t_both_stacks *x, t_both_stacks *fake, t_norm2 *n)
{
	int			i;
	int			j;
	t_stack		*cur;

	printf("%d\n", x->b.top);
	printf("%lld\n", x->b.arr[0]);
	if (x->a.top == -1)
		cur = &x->b;
	else
		cur = &x->a;
	i = 0;
	printf("cur \n");
	for (int i = 0; i < x->a.size; i ++)
	{
		printf("%lld ", x->b.arr[i]);
	}
	printf("\n");
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
	printf("fake \n");
	for (int i = 0; i < x->a.size; i ++)
	{
		printf("%lld ", n[i].fake);
	}
	printf("\n");
	i = -1;
	if (x->a.top == -1)
	{
		while (++i < x->a.size)
			fake->b.arr[i] = n[i].fake;
		fake->b.top = x->b.top;
	}
	else
	{
		while (++i < x->a.size)
			fake->a.arr[i] = n[i].fake;
		fake->a.top = x->a.top;
	}
	printf("fake a \n");
	for (int i = 0; i < x->a.size; i ++)
	{
		printf("%lld ", fake->a.arr[i]);
	}
	printf("\n");
	printf("fake b \n");
	for (int i = 0; i < x->a.size; i ++)
	{
		printf("%lld ", fake->b.arr[i]);
	}
	printf("\n");
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
	// printf("cur stack top, %lld\n", cur_stack->arr[cur_stack->top]);
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
	if (x->b.top == -1)
	{
		// printf("here \n");
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
	// if (x->b.top == -1)
	// {
	// 	for (int i = 0; i < x->a.size; i ++)
	// 	{
	// 		printf("%lld ", x->a.arr[i]);
	// 	}
	// }
	// else if (x->a.top == -1)
	// {
	// 	for (int i = 0; i < x->b.size; i ++)
	// 	{
	// 		printf("%lld ", x->b.arr[i]);
	// 	}
	// }
	// printf("\n");
	radix_sort(len, x, cur_bit + 1);
	return ;
}
