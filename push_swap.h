#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
// # include "typedef.h"
#include <stdio.h>	//

typedef struct s_stack
{
	int		*arr;
	int		top;
	size_t	size;
}	t_stack;

typedef struct s_input
{
	int		nums;
	size_t	idx;
}	t_input;

typedef struct s_darr
{
	void	**arr;
	size_t	size;
	size_t	capacity;
}	t_darr;

typedef struct s_inst_darr
{
	char	**arr;
	size_t	size;
	size_t	capacity;
}	t_inst_darr;

typedef struct s_cnt_instructions
{
	int	pa;
	int	ra;
	int	pb;
	int	rb;
	int	sa;
	int	sb;
	int	rra;
	int	rrb;
}	t_cnt_instructions;

typedef struct s_both_stacks
{
	t_stack		a;
	t_stack		b;
	t_stack		*cur_stack;
	// t_inst_darr	inst;
	char		mode;
}	t_both_stacks;

typedef struct s_bit_ops
{
	void	(*bit_1[2])(t_both_stacks *x, char mode);
	void	(*bit_0)(t_both_stacks *x, char mode);
	void	(*bit_2[2])(t_both_stacks *x, char mode);
}	t_bit_ops;

void	sa(t_both_stacks *x, char mode);
void	pa(t_both_stacks *x, char mode);
void	ra(t_both_stacks *x, char mode);
void	rra(t_both_stacks *x, char mode);
void	sb(t_both_stacks *x, char mode);
void	pb(t_both_stacks *x, char mode);
void	rb(t_both_stacks *x, char mode);
void	rrb(t_both_stacks *x, char mode);
void	sort(t_stack *a);
void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs);
void	init_stacks(t_darr *malloc, t_both_stacks *x, int size);
void	init_malloc_darr(t_darr *mallocs);
long long	ft_my_atoi(const char *str);
int		find_pivot(t_stack *x, t_stack *tmp_x);
void	fill_up_a(t_stack *a, int argc, char *argv[]);
char	is_sorted(t_stack *x, char id);
void	add_inst(t_inst_darr *c, const char *instr);
void	add_malloc(t_darr *c, void *mem);
void	free_mallocs(t_darr *mallocs);
void	malloc_fails(t_darr *mallocs);
void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs);
// void	sort_three_elements_a(t_stack *x);
// void	sort_three_elements_b(t_stack *x);
// int		check_special_cases_a(t_stack *a);
// int		check_special_cases_b(t_stack *a, t_stack *b);
// int		a_to_b(t_stack *a, t_stack *b, t_tmp_stacks *t);
// int		b_to_a(t_stack *a, t_stack *b, t_tmp_stacks *t);
// void	simple_sort(t_stack *a, t_stack *b, t_cnt_instructions *c);
void	max_elem_to_b(t_stack *a, t_stack *b, t_cnt_instructions *c);
void	quick_sort(t_input arr[], size_t l, size_t h);
size_t	partition(t_input arr[], size_t l, size_t h);
void	sort(t_stack *x);
int		validate_input(char *argv[]);
size_t	split_len(char **split);
#endif