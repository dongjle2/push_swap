#include "push_swap.h"

static void	swap(t_input *i, t_input *j)
{
	t_input tmp;

	if (i == j)
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

size_t	partition(t_input arr[], size_t l, size_t h)
{
	size_t	idx_i;
	size_t	idx_j;
	size_t	pivot;

	idx_i = l;
	idx_j = h;
	pivot = arr[idx_i].nums;
	while (idx_i < idx_j)
	{
		// while ((idx_i < h) && (pivot <= arr[idx_i].nums))
		while ((idx_i < h) && (arr[idx_i].nums <= pivot))
			idx_i++;
		while ((l < idx_j) && (pivot < arr[idx_j].nums))
		// while ((l < idx_j) && (arr[idx_j].nums < pivot))
			idx_j--;
		if (idx_i < idx_j)
			swap(&arr[idx_j], &arr[idx_i]);
	}
	swap(&arr[l], &arr[idx_j]);
	return (idx_i);
}

void	quick_sort(t_input arr[], size_t l, size_t h)
{
	size_t	j;

	if (l < h)
	{
		j = partition(arr, l ,h);
		quick_sort(arr, l, j - 1);
		quick_sort(arr, j, h);
	}
}

// void	sort(t_stack *x)
// {
// 	int	h;

// 	h = x->top;
// 	quick_sort(x->arr, 0, h);
// }
