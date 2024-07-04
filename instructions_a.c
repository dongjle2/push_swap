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
//volatile
void	sa(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	b = b;
	if (1 < a->top)
		swap(&(a->arr[a->top]), &(a->arr[a->top - 1]));
	if (mode == 1)
	{
		add_inst(c, "sa\n");
	}
}

void	pa(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	if (-1 < b->top)
	{
		a->top++;
		a->arr[a->top] = b->arr[b->top];
		b->arr[b->top] = 0;
		b->top--;
	}
	if (mode == 1)
	{
		add_inst(c, "pa\n");
	}
}

void	ra(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	int	tmp;
	int	i;

	b = b;
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
		add_inst(c, "ra\n");
	}
}

void	rra(t_stack *a, t_stack *b, t_inst_darr *c, char mode)
{
	int	tmp;
	int	i;

	b = b;
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
		add_inst(c, "rra\n");
	}
}
