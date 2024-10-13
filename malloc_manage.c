/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:32:51 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/13 02:00:59 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_manage_calloc(size_t count, size_t size, t_darr *mallocs)
{
	void	*mem;

	mem = ft_calloc(count, size);
	if (mem == NULL)
		malloc_fails(mallocs);
	add_malloc(mallocs, mem);
	return (mem);
}

void	malloc_fails(t_darr *mallocs)
{
	free_mallocs(mallocs);
	exit(-1);
}

void	add_malloc(t_darr *c, void *mem)
{
	void	**tmp_arr;

	if (c->capacity == c->size)
	{
		c->capacity *= 2;
		tmp_arr = ft_calloc(c->capacity, sizeof(void *));
		if (tmp_arr == NULL)
		{
			free(mem);
			malloc_fails(c);
		}
		ft_memcpy(tmp_arr, c->arr, c->size * sizeof(void *));
		free(c->arr);
		c->arr = NULL;
		c->arr = tmp_arr;
	}
	c->arr[c->size] = mem;
	c->size++;
}

void	free_split(char **split)
{
	size_t	i;
	size_t	num_row;

	i = 0;
	num_row = split_len(split);
	while (i <= num_row)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_mallocs(t_darr *mallocs)
{
	size_t	i;

	i = 0;
	// if (mallocs == NULL)
	// 	return ;
	while (i < mallocs->size)
	{
		free(mallocs->arr[i]);
		i++;
	}
	free(mallocs->arr);
}
