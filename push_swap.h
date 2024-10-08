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

typedef struct s_generic_darr
{
	size_t	capacity;
	size_t	size;
	void	*arr;
}	t_generic_darr;

typedef struct s_darr
{
	void	**arr;
	size_t	size;
	size_t	capacity;
}	t_darr;

typedef struct s_int_darr
{
	int		*arr;
	size_t	size;
	size_t	capacity;
}	t_int_darr;

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
	char		mode;
}	t_both_stacks;

typedef struct s_bit_ops
{
	void	(*bit_0)(t_both_stacks *x, char mode);
	void	(*bit_1[2])(t_both_stacks *x, char mode);
	void	(*bit_2[2])(t_both_stacks *x, char mode);
}	t_bit_ops;

//instructions_a.c
void	sa(t_both_stacks *x, char mode);
void	pa(t_both_stacks *x, char mode);
void	ra(t_both_stacks *x, char mode);
void	rra(t_both_stacks *x, char mode);

//instructions_b.c
void	sb(t_both_stacks *x, char mode);
void	pb(t_both_stacks *x, char mode);
void	rb(t_both_stacks *x, char mode);
void	rrb(t_both_stacks *x, char mode);


void	sort(t_stack *a);
void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs);
void	init_darr(void *darr, size_t elem_size, size_t capacity);
void	init_stacks(t_darr *mallocs, t_both_stacks *x, size_t sz);
void	init_malloc_darr(t_darr *mallocs);
// int		init_int_darr(t_int_darr *darr);
// void		add_darr(t_int_darr *darr, int x);
long long		ft_my_atoi(const char *str);
// int				get_input(t_int_darr *d_arr, t_stack *a, char *argv[]);
int				find_pivot(t_stack *x, t_stack *tmp_x);
unsigned int	get_stack_sz(t_stack *a, char *argv[]);
void	fill_up_a(t_stack *a, int *arr, size_t len_arr);
void	add_inst(t_inst_darr *c, const char *instr);
void	add_malloc(t_darr *c, void *mem);
void	free_mallocs(t_darr *mallocs);
void	free_split(char **split);
void	malloc_fails(t_darr *mallocs);
void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs);
void	max_elem_to_b(t_stack *a, t_stack *b, t_cnt_instructions *c);
void	quick_sort(t_input arr[], size_t l, size_t h);
size_t	partition(t_input arr[], size_t l, size_t h);
void	sort(t_stack *x);
int	validate_input(char **whole_split, int *int_arr, size_t len_arr);

size_t	split_len(char **split);

int	is_int(char **whole_split);
int	find_dup_int(int *int_split ,size_t sz);
int	*str_arr_to_int_arr(char **whole_split, size_t sz);
char	**get_whole_split(char *argv[]);

void	simple_sort(t_both_stacks *stacks);
void	max_on_top(t_both_stacks *stacks);
int		get_max_idx(t_stack a);
void	sort_3_elem(t_both_stacks *stacks);

void	set_ops(char stack, t_bit_ops *ops);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, t_bit_ops ops, int cur_bit);

int	is_sorted(int *arr, size_t sz);
#endif