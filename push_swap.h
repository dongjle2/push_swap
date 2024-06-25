#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
// # include "typedef.h"
#include <stdio.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
}	t_stack;

typedef struct s_both_stacks
{
	t_stack	a;
	t_stack	b;
}	t_both_stacks;

typedef struct s_cnt_instructions
{
	int	pa;
	int	ra;
	int	pb;
	int	rb;
}	t_cnt_instructions;

typedef struct s_bit_ops
{
	// void	(*bit_0)(t_stack *a, t_stack *b);
	// void	(*bit_1[2])(t_stack *a, t_stack *b);
	void	(*bit_2[2])(t_stack *a, t_stack *b);
	void	(*bit_1)(t_stack *a, t_stack *b);
	void	(*bit_0)(t_stack *a, t_stack *b);
}	t_bit_ops;

typedef struct s_input
{
	long long	nums;
	long long	idx;
}	t_input;

// void	swap(long long *i, long long *j);
void	sa(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	sort(t_stack *a);
void	init_stacks(t_both_stacks *x, int size);
// void	init_tmp(t_tmp_stacks *t, int size);
int		find_pivot(t_stack *x, t_stack *tmp_x);
void	fill_up_a(t_stack *a, int argc, char *argv[]);
char	is_sorted(t_stack *x, char id);
void	sort_three_elements_a(t_stack *x);
void	sort_three_elements_b(t_stack *x);
int		check_special_cases_a(t_stack *a);
int		check_special_cases_b(t_stack *a, t_stack *b);
// int		a_to_b(t_stack *a, t_stack *b, t_tmp_stacks *t);
// int		b_to_a(t_stack *a, t_stack *b, t_tmp_stacks *t);
void	simple_sort(t_stack *a, t_stack *b, t_cnt_instructions *c);
void	max_elem_to_b(t_stack *a, t_stack *b, t_cnt_instructions *c);
void	quick_sort(t_input arr[], long long l, long long h);
long long	partition(t_input arr[], long long l, long long h);
void	sort(t_stack *x);
#endif