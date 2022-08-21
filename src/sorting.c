/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/10 18:47:40 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort stack with 2 or 3 numbers only */
void	ft_sort_mini_stack(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (ft_stack_size(a) == 2 && tmp->value > tmp->prev->value)
		sa(a);
	else if (tmp->prev->prev->value < tmp->value
		&& tmp->prev->prev->value < tmp->prev->value)
	{
		if (tmp->value > tmp->prev->value)
			sa(a);
		rra(a);
		return ;
	}
	else if (tmp->value > tmp->prev->value)
	{
		if (tmp->value > tmp->prev->prev->value)
			ra(a);
		else
			sa(a);
	}
	else
	{
		sa(a);
		ra(a);
	}
}

/* start sorting stack A by pushing nodes with lowest value to stack B */
void	ft_sort_small_stack(t_stack *a, t_stack *b)
{
	int		total;
	int		q;
	int		i;

	total = ft_stack_size(a);
	q = total / 2;
	while (q--)
	{
		i = ft_find_position(ft_lowest(a), a);
		total = ft_stack_size(a);
		if (i <= total / 2)
			while (i--)
				ra(a);
		else
			while (i++ < total)
				rra(a);
		pb(a, b);
	}
	if (!ft_sorted_stack(a))
		ft_sort_mini_stack(a);
	while (b->top)
		pa(a, b);
}

/* pre-sort stack A when using radix sort */
static
void	ft_pre_sort_a(int i, int num, t_stack *a, t_stack *b)
{
	int	j;

	j = 0;
	while (j < num)
	{
		if (((a->top->index >> i) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
}

/* sort stack using radix sort */
void	ft_sort_big_stack(t_stack *a, t_stack *b)
{
	unsigned int	size;
	unsigned int	bits;
	unsigned int	i;

	bits = 0;
	size = ft_stack_size(a);
	while (size >> bits)
		bits++;
	i = 0;
	while (i < bits)
	{
		ft_pre_sort_a(i, size, a, b);
		while (b->top)
			pa(a, b);
		i++;
	}
}
