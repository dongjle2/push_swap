#include "push_swap.h"

static void	swap(int *i, int *j)
{
	int tmp;

	if (i == j)
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	sb(t_both_stacks *x, char mode)
{
	t_stack *b;

	b = &x->b;
	if (1 < b->top)
		swap(&(b->arr[b->top]), &(b->arr[b->top - 1]));
	if (mode == 1)
	{
		write(1, "sb\n", 3);
	}
}

void	pb(t_both_stacks *x, char mode)
{
	t_stack *a;
	t_stack *b;

	a = &x->a;
	b = &x->b;
	if (-1 <= a->top)
	{
		b->arr[++b->top] = a->arr[a->top];
		a->arr[a->top] = 0;
		a->top--;
	}
	if (mode == 1)
	{
		write(1, "pb\n", 3);
	}
}

void	rb(t_both_stacks *x, char mode)
{
	int		tmp;
	int		i;
	t_stack *a;
	t_stack *b;

	a = &x->a;
	b = &x->b;
	tmp = b->arr[b->top];
	i = b->top - 1;
	while (-1 < i)
	{
		b->arr[i + 1] = b->arr[i];
		i--;
	}
	b->arr[0] = tmp;
	if (mode == 1)
	{
		write(1, "rb\n", 3);
	}
}

void	rrb(t_both_stacks *x, char mode)
{
	int		tmp;
	int		i;
	t_stack *a;
	t_stack *b;

	a = &x->a;
	b = &x->b;
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = tmp;
	if (mode == 1)
	{
		write(1, "rrb\n", 4);
	}
}
