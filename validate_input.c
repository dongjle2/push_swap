/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:27:22 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/08 16:07:41 by dongjle2         ###   ########.fr       */
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

int	ck_int_range(char *str)
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

// void	add_darr(t_int_darr *darr, int x)
// {
// 	int		*tmp_arr;
// 	size_t	i;

// 	i = 0;
// 	if (darr->capacity == darr->size)
// 	{
// 		darr->capacity *= 2;
// 		tmp_arr = ft_calloc(darr->capacity, sizeof(int));
// 		if (tmp_arr == NULL)
// 			exit(1);
// 		while (i < darr->capacity / 2)
// 		{
// 			tmp_arr[i] = darr->arr[i];
// 			i++;
// 		}
// 		free(darr->arr);
// 		darr->arr = NULL;
// 		darr->arr = tmp_arr;
// 	}
// 	darr->arr[darr->size] = x;
// 	darr->size++;
// 	return ;
// }

int	iterate_arr(int *arr, size_t sz)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < sz - 1)
	{
		j = i + 1;
		while (j < sz)
		{
			if (arr[i] == arr[j])
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

void	cp_argv_to_arr(char **ret, char *argv[])
{
	size_t	i;
	size_t	j;
	size_t	cnt;
	char	**split;

	i = 1;
	cnt = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
		{
			free_split(split);
			exit(1);
		}
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
}

char	**get_whole_split(char *argv[])
{
	size_t	len_row;
	char	**ret;
	char	**split;

	len_row = cnt_whole_str(argv);
	if (len_row == 0)
		exit(0);
	ret = ft_calloc(len_row + 1, sizeof(char *));
	if (ret == NULL)
		exit(1);
	cp_argv_to_arr(ret, argv);
	return (ret);
}

int	is_int(char **whole_split)
{
	size_t	i;

	i = 0;
	while (whole_split[i])
	{
		if (is_signed_digit(whole_split[i]) == 1 || ck_int_range(whole_split[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	*str_arr_to_int_arr(char **whole_split, size_t sz)
{
	size_t	i;
	int		*ret;

	i = 0;
	ret = ft_calloc(sz, sizeof(int));
	while (whole_split[i])
	{
		ret[i] = atoi(whole_split[i]);
		i++;
	}
	return (ret);
}
//sort to find dup int
int	find_dup_int(int *int_split ,size_t sz)
{
	int	ret;

	ret = iterate_arr(int_split, sz);
	return (ret);
}
