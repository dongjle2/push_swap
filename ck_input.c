/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:04:52 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/09 23:18:00 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char **whole_split, int *int_arr, size_t len_arr)
{
	if (is_int(whole_split) == 1 || find_dup_int(int_arr, len_arr) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	is_sorted(int *arr, size_t sz)
{
	size_t	i;

	i = 0;
	while (i < sz - 1)
	{
		if (arr[i + 1] < arr[i])
			return (0);
		i++;
	}
	return (1);
}
