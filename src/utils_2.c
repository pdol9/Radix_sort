/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:49:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/10 18:47:47 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	del_top_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == NULL)
		return (1);
	if (stack->top->next == NULL && stack->top->prev == NULL)
	{
		tmp = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
		free(tmp);
		return (0);
	}
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	free(tmp);
	return (0);
}

int	del_bottom_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->bottom == NULL)
		return (1);
	if (stack->bottom->next == NULL && stack->bottom->prev == NULL)
	{
		tmp = stack->bottom;
		stack->bottom = NULL;
		stack->top = NULL;
		free(tmp);
		return (0);
	}
	tmp = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	free(tmp);
	return (0);
}

long	ft_atol(const char *string)
{
	int		i;
	long	r;
	long	sign;

	i = 0;
	r = 0;
	sign = 1;
	while ((string[i] == ' ') || (string[i] == '\t') || (string[i] == '\n')
		|| (string[i] == '\v') || (string[i] == '\r' ) || (string[i] == '\f'))
	{
		i++;
	}
	if (string[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		r = r * 10 + (string[i] - '0');
		i++;
	}
	return (sign * r);
}
