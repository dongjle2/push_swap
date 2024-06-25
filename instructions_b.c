#include "push_swap.h"

static void	swap(long long *i, long long *j)
{
	long long tmp;

	if (i == j)
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	sb(t_stack *a, t_stack *b)
{
	a = a;
	if (1 < b->top)
		swap(&(b->arr[b->top]), &(b->arr[b->top - 1]));
	// write(1, "sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (-1 <= a->top)
	{
		b->arr[++b->top] = a->arr[a->top];
		a->arr[a->top] = 0;
		a->top--;
	}
	// write(1, "pb\n", 3);
}

void	rb(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	a = a;
	tmp = b->arr[b->top];
	i = b->top - 1;
	while (-1 < i)
	{
		b->arr[i + 1] = b->arr[i];
		i--;
	}
	b->arr[0] = tmp;
	// write(1, "rb\n", 3);
}

void	rrb(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	a = a;
	tmp = b->arr[0];
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = tmp;
	// write(1, "rrb\n", 4);
}
