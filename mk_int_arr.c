/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_int_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:49:27 by dongjle2          #+#    #+#             */
/*   Updated: 2024/10/13 00:45:26 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int	cp_each_element(char **whole_split, char **split, size_t *cnt)
// {
// 	int	ret;

// 	ret = 0;
// 	if (*split == NULL)
// 		return (0);
// 	whole_split[*cnt] = ft_strdup(*split);
// 	if (whole_split[*cnt] == NULL)
// 	{
// 		ret = 1;
// 		return (1);
// 	}
// 	(*cnt)++;
// 	if (cp_each_element(whole_split, split + 1, cnt) == 1)
// 		return (1);
// }

int	cp_each_element(char **whole_split, char **split, size_t *cnt)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		whole_split[*cnt] = ft_strdup(split[i]);
		if (whole_split[*cnt] == NULL)
			return (1);
		i++;
		(*cnt)++;
	}
	return (0);
}

int	cp_argv_to_arr(char **whole_split, char *argv[])
{
	size_t	i;
	size_t	cnt;
	int		ret;
	char	**split;

	i = 0;
	cnt = 0;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return (1);
		ret = cp_each_element(whole_split, split, &cnt);
		free_split(split);
		if (ret == 1)
			return (1);
		else
			split = NULL;
	}
	whole_split[cnt] = 0;
	return (0);
}

char	**get_whole_split(char *argv[])
{
	size_t	len_row;
	int		ret;
	char	**whole_split;

	len_row = cnt_whole_str(argv);
	if (len_row == 0)
		exit(0);
	whole_split = ft_calloc(len_row + 1, sizeof(char *));
	if (whole_split == NULL)
		exit(1);
	ret = cp_argv_to_arr(whole_split, argv);
	if (ret == 1)
	{
		free_split(whole_split);
		exit(1);
	}
	return (whole_split);
}

int	*str_arr_to_int_arr(char **whole_split, size_t sz)
{
	size_t	i;
	int		*ret;

	i = 0;
	ret = ft_calloc(sz, sizeof(int));
	if (ret == NULL)
	{
		free_split(whole_split);
		exit(1);
	}
	while (whole_split[i])
	{
		ret[i] = ft_atoi(whole_split[i]);
		i++;
	}
	return (ret);
}
