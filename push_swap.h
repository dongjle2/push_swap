/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:43:26 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/10 02:54:36 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
// # include "typedef.h"
# include <stdio.h>	//

typedef struct s_stack
{
	unsigned int	*arr;
	int				top;
	size_t			size;
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

//sort_algo.c
void	radix_sort(int len, t_both_stacks *x, int cur_bit);
void	quick_sort(t_input arr[], size_t l, size_t h);
size_t	partition(t_input arr[], size_t l, size_t h);
void	clear_stack_b(t_both_stacks *x);

//main.c
void	setup_stacks(char *argv[], t_darr *mallocs, \
		t_both_stacks *stacks, t_both_stacks *fake_stacks);
void	normalize(t_darr *mallocs, t_stack *a);
void	normalize_2(t_darr *mallocs, t_both_stacks *x, t_both_stacks *fake);
void	change_value(t_stack *cur, t_stack *fake_stack, unsigned int *tmp);

//validate_input.c
int		is_signed_digit(char *str);
int		ck_int_range(char *str);
int		iterate_arr(int *arr, size_t sz);
int		is_int(char **whole_split);
int		find_dup_int(int *int_split, size_t sz);

//stack_utils.c
void	set_cur_stack(t_both_stacks *x, t_both_stacks *fake);
void	fill_up_a(t_stack *a, int *arr, size_t len_arr);
void	exec_ops(t_both_stacks *x, t_stack *cur_stack, \
		t_bit_ops ops, int cur_bit);
void	clear_stack(t_both_stacks *x, t_stack *cur_stack, \
		t_bit_ops ops, int cur_bit);

//ck_input.c
int		is_sorted(int *arr, size_t sz);
int		validate_input(char **whole_split, int *int_arr, size_t len_arr);

//malloc_manage.c
void	add_malloc(t_darr *c, void *mem);
void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs);
void	malloc_fails(t_darr *mallocs);
void	free_mallocs(t_darr *mallocs);
void	free_split(char **split);

//mk_input_arr.c
size_t	cnt_whole_str(char *argv[]);
int		cp_each_element(char **whole_split, char **split, size_t *cnt);
int		cp_argv_to_arr(char **whole_split, char *argv[]);
char	**get_whole_split(char *argv[]);
int		*str_arr_to_int_arr(char **whole_split, size_t sz);

//simple_sort.c
void	simple_sort(t_both_stacks *stacks);
void	max_on_top(t_both_stacks *stacks);
int		get_max_idx(t_stack a);
void	sort_3_elem(t_both_stacks *stacks);

//init.c
void	init_stacks(t_darr *mallocs, t_both_stacks *x, size_t sz);
void	init_malloc_darr(t_darr *mallocs);

//helper.c
long	ft_my_atoi(const char *str);
size_t	split_len(char **split);
void	set_ops(char stack, t_bit_ops *ops);
int		get_ternary_len(int num);
#endif