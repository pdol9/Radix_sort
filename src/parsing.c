/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/06/02 21:17:26 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return positive value for any non digit values in the input */
static
int	ft_false_digit(char *str)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			val++;
		i++;
	}
	if (i == 1 && str[0] == '-')
		val = 2;
	return (val);
}

/* start parsing the input */
static
int	ft_digit_check(t_input *set)
{
	int	r;
	int	k;

	k = set->j;
	while (k < set->i)
	{
		r = ft_false_digit(set->v[k]);
		if (r)
		{
			if (r == 1 && !ft_strncmp(set->v[k], "-", 1))
				;
			else
				return (1);
		}
		k++;
	}
	return (0);
}

/* return a positive value for any duplicates
 * or any int value greater than MAX/MIN
 */
static
int	ft_num_check(t_stack *a, t_input *set)
{
	t_node	*tmp;
	t_node	*t2;
	int		k;

	k = set->j;
	while (set->v[k])
	{
		if (ft_atol(set->v[k]) > INT_MAX || ft_atol(set->v[k]) < INT_MIN)
			return (1);
		k++;
	}
	k = 0;
	tmp = a->top;
	while (tmp)
	{
		t2 = a->top->prev;
		while (t2)
		{
			if (t2->value == tmp->value && tmp != t2)
				k++;
			t2 = t2->prev;
		}
		tmp = tmp->prev;
	}
	return (k);
}

void	ft_free_memory(t_stack *stack, t_input *input)
{
	int	i;

	if (input->v && input->j == 0)
	{
		i = 0;
		while (i < input->i)
			free(input->v[i++]);
		free(input->v);
	}
	if (input)
		free(input);
	free_stack(stack);
}

/* verify for invalid input and than return error message if necessary */
void	ft_error(t_stack *a, t_input *set, int argc)
{
	if (argc < 2)
	{
		ft_free_memory(a, set);
		exit(1);
	}
	if (ft_digit_check(set) || ft_num_check(a, set))
	{
		write(2, "Error\n", 6);
		ft_free_memory(a, set);
		exit(1);
	}
	if (ft_sorted_stack(a))
	{
		ft_free_memory(a, set);
		exit(0);
	}
}
