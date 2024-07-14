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

int	ck_sign_digit(char *str)
{
	size_t	i;

	i = 0;
	if ((*str == '+') || (*str == '-'))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 1)
			str++;
		else
			return (1);
	}
	return (0);
}

int	validate_input(char *argv[])
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
			if (ck_sign_digit(split[k]) == 1)
			{
				free(split);
				return (1);
			}
			k++;
		}
		//ck_input_range
		free(split);
		split = NULL;
		i++;
	}
	return (0);
}
