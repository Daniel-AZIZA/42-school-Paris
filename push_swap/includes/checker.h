/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:43:49 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:43:50 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct s_stack		t_stack;
struct						s_stack
{
	int		nb;
	t_stack	*next;
};

typedef	struct s_operation	t_operation;
struct						s_operation
{
	char		*str;
	void		(*f)(t_stack **first);
	void		(*push)(t_stack **stack_a, t_stack **stack_b);
	t_operation	*next;
};

void						print_stack_color(t_stack *a, t_stack *b,
							t_operation *op);
void						print_stack_2(t_stack *a, t_stack *b);
void						is_order(t_stack *stack_a, t_stack *stack_b);
int							parsing_arg(char **av, int *flag);
int							get_flag(char **av, int *flag);
int							get_operation(char ***operation, int ret,
							int total_size);
char						**ft_split(const char *s, char c);
t_operation					*find_and_stock_op(char **operation,
							t_operation **op, char **av);
t_stack						*char_to_int(int ac, char **av, t_stack **stack);
int							ft_atoi(char *str);
void						call_op(t_operation *op, t_stack *stack, int flag);
t_stack						*ft_create_elem_2(int nbr);
void						pa(t_stack **stack_a, t_stack **stack_b);
void						pb(t_stack **stack_a, t_stack **stack_b);
void						swap_a(t_stack **first);
void						swap_b(t_stack **first);
void						ss(t_stack **stack_a, t_stack **stack_b);
void						ra_rb(t_stack **first);
void						rr(t_stack **stack_a, t_stack **stack_b);
void						rra_rrb(t_stack **first);
void						rrr(t_stack **stack_a, t_stack **stack_b);
void						print_stack(t_stack *a, t_stack *b,
							t_operation *op);
void						ft_list_reverse_fun(t_stack *begin_list);
void						free_all(char **operation, t_stack *stack,
							t_operation *op);

#endif
