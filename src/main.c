/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/06/02 21:23:39 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* verify if stack is already sorted */
int	ft_sorted_stack(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (!tmp)
		return (1);
	while (tmp->prev)
	{
		if (tmp->value > tmp->prev->value)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

/* link input values into the stack A */
static
void	ft_link_up(t_stack *a, t_input *set)
{
	int	i;

	i = set->j;
	while (i < set->i)
	{
		if (push_to_bottom(a, ft_atol(set->v[i]), 0))
		{
			ft_free_memory(a, set);
			exit(1);
		}
		i++;
	}
}

/* initializing values, in case of a shell variable ($ARG)
 * or direct terminal input
 */
static
t_input	*ft_init_values(int argc, char **argv)
{
	t_input	*val;

	val = malloc(sizeof(t_input));
	if (!val)
		return (NULL);
	if (argc == 2)
	{
		val->v = ft_split(argv[1], ' ');
		val->i = 0;
		val->j = 0;
		while (val->v[val->i])
			val->i++;
	}
	else
	{
		val->v = argv;
		val->i = argc;
		val->j = 1;
	}
	return (val);
}

void	ft_start_sorting(t_input *set, t_stack *a)
{
	t_stack	*b;
	int		size;

	size = ft_stack_size(a);
	if (size == 1)
	{
		ft_free_memory(a, set);
		exit(1);
	}
	b = init_stack();
	if (size < 4)
		ft_sort_mini_stack(a);
	else if (size < 6)
		ft_sort_small_stack(a, b);
	else
		ft_sort_big_stack(a, b);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_input	*set;
	t_stack	*a;

	set = ft_init_values(argc, argv);
	a = init_stack();
	ft_link_up(a, set);
	ft_error(a, set, argc);
	ft_indexing(a);
	ft_start_sorting(set, a);
	ft_free_memory(a, set);
	return (0);
}
