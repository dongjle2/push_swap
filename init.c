/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:42:59 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/09 23:51:55 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_darr *mallocs, t_both_stacks *x, size_t sz)
{
	x->a.arr = ft_manage_calloc(sz, sizeof(int), mallocs);
	if (x->a.arr == NULL)
		malloc_fails(mallocs);
	x->b.arr = ft_manage_calloc(sz, sizeof(int), mallocs);
	if (x->b.arr == NULL)
		malloc_fails(mallocs);
	x->a.top = sz - 1;
	x->a.size = sz;
	x->b.top = -1;
	x->b.size = sz;
	x->mode = 0;
	x->cur_stack = &x->a;
}

void	init_malloc_darr(t_darr *mallocs)
{
	mallocs->capacity = 1;
	mallocs->size = 0;
	mallocs->arr = ft_calloc(mallocs->capacity, sizeof(void *));
	if (mallocs->arr == NULL)
		exit(-1);
}
