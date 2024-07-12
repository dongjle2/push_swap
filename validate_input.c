/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:27:22 by dongjle2          #+#    #+#             */
/*   Updated: 2024/07/12 21:40:23 by dongjle2         ###   ########.fr       */
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

int	validate_input(char *argv[])
{
	size_t	i;
	size_t	num_rows;
	size_t	k;
	char	**split;

	i = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		num_rows = split_len(split);
		k = 0;
		while (split[k])
		{
			if (ck_sign_digit(split[k]) == 1)
			{
				free_split(split, num_rows);
				return (1);
			}
			k++;
		}
		i++;
	}
}
