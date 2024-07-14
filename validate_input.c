/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:27:22 by dongjle2          #+#    #+#             */
/*   Updated: 2024/07/14 18:55:19 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	split_len(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ck_sign_digit(char *str)
{
	size_t	i;
	char	digit_found;

	i = 0;
	digit_found = 0;
	if ((*str == '+') || (*str == '-'))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 1)
		{
			digit_found = 1;
			str++;
		}
		else
			return (1);
	}
	if (digit_found == 0)
		return (1);
	return (0);
}

int	ck_input_range(char *str)
{
	long long	tmp;

	tmp = ft_my_atoi(str);
	if ((INT_MAX < tmp) || (tmp < INT_MIN))
		return (1);
	return (0);
}

void	free_split(char **split)
{
	size_t	i;
	size_t	num_row;

	i = 0;
	num_row = split_len(split);
	while (i <= num_row)	//ft_split has last NULL in the end
	{
		free(split[i]);
		// split[i] = NULL;
		i++;
	}
	free(split);
	// split = NULL;
}

int	validate_nums(char *argv[])
{
	size_t	i;
	size_t	k;
	char	**split;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		k = 0;
		while (split[k])
		{
			if (ck_sign_digit(split[k]) == 1 || ck_input_range(split[k]) == 1)
			{
				free_split(split);
				return (1);
			}
			k++;
		}
		free_split(split);
		split = NULL;
		i++;
	}
	return (0);
}

int	init_int_darr(t_int_darr *darr)
{
	darr->capacity = 128;
	darr->size = 0;
	darr->arr = ft_calloc(darr->capacity, sizeof(int));
	if (darr->arr == NULL)
		return (-1);
	return (0);
}

int	add_darr(t_int_darr *darr, int x)
{
	int		*tmp_arr;
	size_t	i;

	i = 0;
	if (darr->capacity == darr->size)
	{
		darr->capacity *= 2;
		tmp_arr = ft_calloc(darr->capacity, sizeof(int));
		if (tmp_arr == NULL)
			return (-1);
		while (i < darr->capacity / 2)
		{
			tmp_arr[i] = darr->arr[i];
			i++;
		}
		free(darr->arr);
		darr->arr = NULL;
		darr->arr = tmp_arr;
	}
	darr->arr[darr->size] = x;
	darr->size++;
	return (0);
}

int	find_dup(char *argv[])
{
	size_t		i;
	size_t		j;
	t_int_darr	d_arr;
	char		**split;

	i = 1;
	init_int_darr(&d_arr);
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (add_darr(&d_arr, ft_atoi(split[j])) != 0)
				return (-1);
			j++;
		}
		i++;
	}
	for (size_t i = 0; i < d_arr.size - 1; i++)
	{
		for (size_t j = 1; j < d_arr.size; j++)
		{
			if (d_arr.arr[i] == d_arr.arr[j])
				return (1);
		}
	}
	return (0);
}

int	validate_input(char *argv[])
{
	if (validate_nums(argv) == 1 || find_dup(argv) == 1)
		return (1);
	return (0);
}
