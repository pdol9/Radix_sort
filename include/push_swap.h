/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/06/29 20:29:27 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <libft.h>

typedef struct s_node
{
	unsigned int	index;
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
}	t_stack;

typedef struct s_input
{
	char			**v;
	int				i;
	int				j;
	int				s;
}	t_input;

/* push swap functions */
int		ft_stack_size(t_stack *stack);
int		ft_sorted_stack(t_stack *a);
void	ft_error(t_stack *a, t_input *set);
void	ft_error_handling(t_stack *stack, t_input *input, int flag);
void	ft_start_sorting(t_stack *a, t_input *set);
void	ft_sort_mini_stack(t_stack *a);
void	ft_sort_small_stack(t_stack *a, t_stack *b);
void	ft_sort_big_stack(t_stack *a, t_stack *b);
void	ft_indexing(t_stack *a);
int		ft_init_pos(t_node *n, t_stack *a);
int		ft_find_position(t_node *node, t_stack *stack);
t_node	*ft_lowest(t_stack *stack);

/* utils */
t_stack	*init_stack(void);
t_node	*init_node(int value, int index);
int		push_to_top(t_stack *stack, int value, int index);
int		push_to_bottom(t_stack *stack, int value, int index);
int		del_top_stack(t_stack *stack);
int		del_bottom_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_input(char **vector, int size);

/* push swap operations */
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);

#endif
