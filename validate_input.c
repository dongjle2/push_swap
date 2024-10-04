/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:27:22 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/04 03:08:03 by dongjle2         ###   ########.fr       */
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

int	is_signed_digit(char *str)
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
	while (i <= num_row)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// void	init_int_darr(t_int_darr *darr)
// {
// 	darr->capacity = 128;
// 	darr->size = 0;
// 	darr->arr = ft_calloc(darr->capacity, sizeof(int));
// 	if (darr->arr == NULL)
// 		exit(1);
// }

void	add_darr(t_int_darr *darr, int x)
{
	int		*tmp_arr;
	size_t	i;

	i = 0;
	if (darr->capacity == darr->size)
	{
		darr->capacity *= 2;
		tmp_arr = ft_calloc(darr->capacity, sizeof(int));
		if (tmp_arr == NULL)
			exit(1);
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
	return ;
}

int	iterate_arr(t_int_darr *d_arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < d_arr->size - 1)
	{
		j = i + 1;
		while (j < d_arr->size)
		{
			if (d_arr->arr[i] == d_arr->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	cnt_whole_str(char *argv[])
{
	size_t	i;
	size_t	ret;
	char	**split;

	i = 1;
	ret = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			exit(1);
		ret += split_len(split);
		free_split(split);
		split = NULL;
		i++;
	}
	return (ret);
}

char	**cp_split_to_arr(char **ret, char *argv[])
{
	size_t	i;
	size_t	j;
	size_t	cnt;
	char	**split;

	i = 0;
	cnt = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			exit(1);
		j = 0;
		while (split[j] != 0)
		{
			ret[cnt] = split[j];
			cnt++;
			j++;
		}
		i++;
	}
	ret[cnt] = 0;
	return (ret);
}

char	**get_whole_split(char *argv[])
{
	size_t	len_row;
	size_t	i;
	size_t	j;
	char	**ret;
	char	**split;

	i = 0;
	len_row = cnt_whole_str(argv);
	ret = ft_calloc(len_row + 1, sizeof(char *));
	if (ret == NULL)
		exit(1);
	ret = cp_split_to_arr(ret, argv);
	return (ret);
}

int	is_int(char **whole_split)
{
	size_t	i;

	i = 0;
	while (whole_split[i])
	{
		if (is_signed_digit(whole_split[i]) == 1\
			|| ck_input_range(whole_split[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
/*
int	is_int(char *argv[])
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
			if (is_signed_digit(split[k]) == 1 || ck_input_range(split[k]) == 1)
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
*/

int	find_dup_int(char *argv[])	//fix using sort
{
	size_t		i;
	size_t		j;
	int			ret;
	t_int_darr	d_arr;
	char		**split;

	i = 1;
	init_darr(&d_arr, sizeof(int), 128);
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			add_darr(&d_arr, ft_atoi(split[j]));
			j++;
		}
		free_split(split);
		split = NULL;
		i++;
	}
	ret = iterate_arr(&d_arr);
	free(d_arr.arr);
	return (ret);
}

int	validate_input(char *argv[])
{
	char	**whole_split;
	
	whole_split = get_whole_split(argv);
	if (is_int(whole_split) == 1 || find_dup_int(argv) == 1)
	{
		free_split(whole_split);
		return (1);
	}
	return (0);
}
