/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:42:11 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:42:13 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_list_reverse_fun(t_stack *begin_list)
{
	int		count;
	int		i;
	int		j;
	t_stack	*current;
	int		tmp;

	count = 0;
	current = begin_list;
	while (current && ++count)
		current = current->next;
	i = 0;
	while (i < count - 1)
	{
		j = i;
		current = begin_list;
		while (current && current->next && j < count - 1)
		{
			tmp = current->nb;
			current->nb = current->next->nb;
			current->next->nb = tmp;
			current = current->next;
			++j;
		}
		++i;
	}
}

int		count_stack(t_stack *a, t_stack *b,
		unsigned int *count_a, unsigned int *count_b)
{
	t_stack *tmp;

	tmp = NULL;
	*count_a = 0;
	*count_b = 0;
	tmp = a;
	while (tmp)
	{
		(*count_a)++;
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp)
	{
		(*count_b)++;
		tmp = tmp->next;
	}
	if (*count_a > *count_b)
		return (*count_a);
	else
		return (*count_b);
}

void	print_stack_2_annexe(t_stack *tmp, t_stack *tmp_2)
{
	unsigned int	count_a;
	unsigned int	count_b;
	unsigned int	t;

	t = count_stack(tmp, tmp_2, &count_a, &count_b);
	while (t > 0)
	{
		if (t <= count_a)
		{
			printf("%d ", tmp->nb);
			tmp = tmp->next;
		}
		if (t <= count_b)
		{
			if (tmp_2)
				printf(" %d", tmp_2->nb);
			tmp_2 = tmp_2->next;
		}
		printf("\n");
		t--;
	}
}

void	print_stack_2(t_stack *a, t_stack *b)
{
	t_stack			*tmp;
	t_stack			*tmp_2;

	tmp = a;
	tmp_2 = b;
	if (b)
		ft_list_reverse_fun(tmp_2);
	print_stack_2_annexe(tmp, tmp_2);
	if (b)
		ft_list_reverse_fun(b);
}

void	print_stack(t_stack *a, t_stack *b, t_operation *op)
{
	static int	first = 1;

	if (first == 0)
		printf("exec %s:\n", op->str);
	if (first == 1)
		printf("\ninit : \n\n");
	print_stack_2(a, b);
	printf("_  _\n");
	printf("a  b\n\n");
	first = 0;
}
