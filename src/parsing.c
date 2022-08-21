/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/29 20:28:10 by pdolinar         ###   ########.fr       */
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
	t_node	*tmp2;
	int		err;

	err = set->j;
	while (set->v[err])
	{
		if (ft_atol(set->v[err]) > INT_MAX || ft_atol(set->v[err]) < INT_MIN)
			return (err + 1);
		err++;
	}
	err = 0;
	tmp = a->top;
	while (tmp)
	{
		tmp2 = a->top->prev;
		while (tmp2)
		{
			if (tmp2->value == tmp->value && tmp != tmp2)
				err++;
			tmp2 = tmp2->prev;
		}
		tmp = tmp->prev;
	}
	return (err);
}

void	ft_error_handling(t_stack *stack, t_input *input, int flag)
{
	free_stack(stack);
	if (input->s)
		free_input(input->v, input->i);
	free(input);
	exit(flag);
}

/* verify for invalid input and than return error message if necessary */
void	ft_error(t_stack *a, t_input *set)
{
	if (ft_digit_check(set) || ft_num_check(a, set))
	{
		write(2, "Error\n", 6);
		ft_error_handling(a, set, 1);
	}
	if (ft_sorted_stack(a))
		ft_error_handling(a, set, 0);
}
