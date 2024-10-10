/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:27:22 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/09 23:56:00 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_signed_digit(char *str)
{
	char	digit_found;

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

int	is_int(char **whole_split)
{
	size_t	i;

	i = 0;
	while (whole_split[i])
	{
		if (is_signed_digit(whole_split[i]) == 1 \
			|| ck_int_range(whole_split[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

//sort to find dup int
int	find_dup_int(int *int_split, size_t sz)
{
	int	ret;

	ret = iterate_arr(int_split, sz);
	return (ret);
}
