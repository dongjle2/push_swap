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

void	sb(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	a = a;
	if (1 < b->top)
		swap(&(b->arr[b->top]), &(b->arr[b->top - 1]));
	if (mode == 1)
	{
		add_inst(c, "sb\n");
	}
}

void	pb(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	if (-1 <= a->top)
	{
		b->arr[++b->top] = a->arr[a->top];
		a->arr[a->top] = 0;
		a->top--;
	}
	if (mode == 1)
	{
		add_inst(c, "pb\n");
	}
}

void	rb(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
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
	if (mode == 1)
	{
		add_inst(c, "rb\n");
	}
}

void	rrb(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
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
	if (mode == 1)
	{
		add_inst(c, "rrb\n");
	}
}
