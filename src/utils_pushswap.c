/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:49:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/10 18:48:00 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return the node with the lowest value in the stack */
t_node	*ft_lowest(t_stack *stack)
{
	t_node	*tmp;
	t_node	*l;

	tmp = stack->top;
	l = tmp;
	while (tmp)
	{
		if (tmp->value < l->value)
			l = tmp;
		tmp = tmp->prev;
	}
	return (l);
}

/* find index position of a specific node */
int	ft_find_position(t_node *node, t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	if (!tmp || !node)
		return (0);
	while (tmp)
	{
		if (node->value == tmp->value)
			return (i);
		tmp = tmp->prev;
		i++;
	}
	return (i);
}

int	ft_stack_size(t_stack *stack)
{
	t_node			*node;
	unsigned int	i;

	i = 0;
	node = stack->top;
	while (node)
	{
		node = node->prev;
		i++;
	}
	return (i);
}

/* index all nodes based on their value */
void	ft_indexing(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->index = ft_init_pos(tmp, a);
		tmp = tmp->prev;
	}
}

/* return index of a node by its value */
int	ft_init_pos(t_node *n, t_stack *a)
{
	t_node			*tmp;
	unsigned int	index;

	index = 0;
	tmp = a->top;
	while (tmp)
	{
		if (n->value > tmp->value)
			index++;
		tmp = tmp->prev;
	}
	return (index);
}
