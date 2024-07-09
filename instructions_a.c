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
//volatile
void	sa(t_both_stacks *x, char mode)
{
	t_stack *a;

	a = &x->a;
	if (1 < a->top)
		swap(&(a->arr[a->top]), &(a->arr[a->top - 1]));
	if (mode == 1)
	{
		write(1, "sa\n", 3);
	}
}

void	pa(t_both_stacks *x, char mode)
{
	t_stack *a;
	t_stack *b;

	a = &x->a;
	b = &x->b;
	if (-1 < b->top)
	{
		a->top++;
		a->arr[a->top] = b->arr[b->top];
		b->arr[b->top] = 0;
		b->top--;
	}
	if (mode == 1)
	{
		write(1, "pa\n", 3);
	}
}

void	ra(t_both_stacks *x, char mode)
{
	int		tmp;
	int		i;
	t_stack *a;

	a = &x->a;
	tmp = a->arr[a->top];
	i = a->top -1;
	while (-1 < i)
	{
		a->arr[i + 1] = a->arr[i];
		i--;
	}
	a->arr[0] = tmp;
	if (mode == 1)
	{
		write(1, "ra\n", 3);
	}
}

void	rra(t_both_stacks *x, char mode)
{
	int	tmp;
	int	i;
	t_stack *a;

	a = &x->a;
	tmp = a->arr[0];
	i = 0;
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = tmp;
	if (mode == 1)
	{
		write(1, "rra\n", 4);
	}
}
