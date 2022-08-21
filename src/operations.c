/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:19:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/10 18:47:19 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Swap the top (first) two numbers in stack A;
 *	do nothing if there is only one or no elements
 */
void	sa(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (a->top == NULL || a->top->prev == NULL)
		return ;
	tmp = init_node(a->top->value, a->top->index);
	if (tmp == NULL)
		return ;
	del_top_stack(a);
	tmp2 = init_node(a->top->value, a->top->index);
	if (tmp2 == NULL)
		return ;
	del_top_stack(a);
	if (push_to_top(a, tmp->value, tmp->index)
		|| push_to_top(a, tmp2->value, tmp2->index))
		return ;
	free(tmp);
	free(tmp2);
	write(1, "sa\n", 3);
}

/* take the first element at the top of B and put it on the top of A
 *	do nothing if B is empty
 */
void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->top == NULL)
		return ;
	tmp = init_node(b->top->value, b->top->index);
	if (tmp == NULL)
		return ;
	del_top_stack(b);
	if (push_to_top(a, tmp->value, tmp->index))
		return ;
	free(tmp);
	write(1, "pa\n", 3);
}

/* take the first element at the top of A and put it on the top of B */
void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->top == NULL)
		return ;
	tmp = init_node(a->top->value, a->top->index);
	if (tmp == NULL)
		return ;
	del_top_stack(a);
	if (push_to_top(b, tmp->value, tmp->index))
		return ;
	free(tmp);
	write(1, "pb\n", 3);
}

/* top number in A goes to bottom of A */
void	ra(t_stack *a)
{
	t_node	*tmp;

	if (a->top == NULL || a->top->prev == NULL)
		return ;
	tmp = init_node(a->top->value, a->top->index);
	if (tmp == NULL)
		return ;
	del_top_stack(a);
	if (push_to_bottom(a, tmp->value, tmp->index))
		return ;
	free(tmp);
	write(1, "ra\n", 3);
}

/* bottom number in A goes to the top of A */
void	rra(t_stack *a)
{
	t_node	*tmp;

	if (a->top == NULL || a->top->prev == NULL)
		return ;
	tmp = init_node(a->bottom->value, a->bottom->index);
	if (tmp == NULL)
		return ;
	del_bottom_stack(a);
	if (push_to_top(a, tmp->value, tmp->index))
		return ;
	free(tmp);
	write(1, "rra\n", 4);
}
