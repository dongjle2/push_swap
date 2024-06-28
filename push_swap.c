#include "push_swap.h"

int	ft_max(a, b)
{
	if (a < b)
		return (b);
	return (a);
}

int	find_max(t_stack *x)
{
	int	i;
	int	max;
	int	idx;

	i = 0;
	max = -INT_MIN;
	idx = -1;
	while (i < x->size)
	{
		if (max < x->arr[i])
		{
			max = x->arr[i];
			idx = i;
		}
		i++;
	}
	// printf("max idx= %d\n", idx);
	return (idx);
}

// void	max_elem_to_b(t_stack *a, t_stack *b, t_cnt_instructions *c)
// {
// 	int		max_idx;
// 	void	(*op)(t_stack *a, t_stack *b);
// 	int		num_op;

// 	max_idx = find_max(a);
// 	if (max_idx < a->top / 2)
// 		op = rra;
// 	else
// 		op = ra;
// 	if (op == rra)
// 		num_op = max_idx + 1;
// 	else
// 		num_op = a->top - max_idx;

// 	while (num_op)
// 	{
// 		op(a, b);
// 		num_op--;
// 	}
// 	pb(a, b);
// }

// void	simple_sort(t_stack *a, t_stack *b, t_cnt_instructions *c)
// {
// 	// printf("%d\n", a->top);
// 	if (a->top < 3)
// 	{
// 		sort_three_elements_a(a);
// 		return ;
// 	}
// 	else
// 	{
// 		max_elem_to_b(a, b, c);
// 		simple_sort(a, b, c);
// 		pa(a, b);
// 		ra(a, b);
// 	}
// }
/*

int	a_to_b(t_stack *a, t_stack *b, t_tmp_stacks *t)
{
	int	pivot;
	int	rep;
	int	i;
	int	cnt_ra;

	if (check_special_cases_a(a) == 0)
		return (-1);
	pivot = find_pivot(a, &t->tmp_a);
	rep = a->top + 1;
	cnt_ra = 0;
	i = 0;
	while (rep--)
	{
		if (a->arr[a->top] <= pivot)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
			cnt_ra += 1;
		}
	}
	while (i++ < cnt_ra)
		rra(a);
	if (a_to_b(a, b ,t) == -1)
	{
		b_to_a(a, b, t);
		return (-1);
	}
	
	return (0);
}

int	b_to_a(t_stack *a, t_stack *b, t_tmp_stacks *t)
{
	int	pivot;
	int	rep;
	int	i;
	int	cnt_rb;

	if (check_special_cases_b(a, b) == 0)
		return (-1);
	rep = b->top + 1;
	pivot = find_pivot(b, &t->tmp_b);
	cnt_rb = 0;
	i = 0;
	while (rep--)
	{
		if (b->arr[b->top] >= pivot)
		{
			pa(a, b);
		}
		else
		{
			rb(b);
			cnt_rb += 1;
		}
	}
	while (i++ < cnt_rb)
		rrb(b);
	// if (a_to_b(a, b ,t) == -1)
	// 	return (-1);
	// {
	// 	b_to_a(a, b, t);
	// 	return (-1);
	// }
	
	return (0);
}

// int	find_pivot(t_stack *x, t_stack *tmp_x)
// {
// 	ft_bzero(tmp_x->arr, x->size * sizeof(int));
// 	ft_memmove(tmp_x->arr, x->arr, (x->top + 1) * sizeof(int));
// 	tmp_x->size = x->top + 1;
// 	tmp_x->top = tmp_x->size - 1;
// 	sort(tmp_x);
// 	return (tmp_x->arr[tmp_x->top / 2]);
// }

*/