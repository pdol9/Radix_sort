/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:49:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/10 18:48:21 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function returns a pointer to the allocated stack */
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

/* function returns a pointer to the allocated node */
t_node	*init_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	push_to_top(t_stack *stack, int value, int index)
{
	t_node	*node;

	node = init_node(value, index);
	if (!node)
		return (1);
	node->prev = stack->top;
	stack->top = node;
	if (node->prev == NULL)
		stack->bottom = node;
	else
		node->prev->next = node;
	return (0);
}

int	push_to_bottom(t_stack *stack, int value, int index)
{
	t_node	*node;

	node = init_node(value, index);
	if (!node)
		return (1);
	node->next = stack->bottom;
	stack->bottom = node;
	if (node->next == NULL)
		stack->top = node;
	else
		node->next->prev = node;
	return (0);
}

void	free_stack(t_stack *stack)
{
	while (stack != NULL && stack->bottom != NULL)
		del_bottom_stack(stack);
	stack->bottom = NULL;
	stack->top = NULL;
	free(stack);
}
