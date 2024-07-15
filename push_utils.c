/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:53:30 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/15 20:41:00 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	aux = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	o;

	o = 1;
	i = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-')
		o = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i ++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i ++;
	}
	return (res * o);
}

int ft_lstsize(t_stack *stack)
{
	int count;

	count = 0;
	while(stack)
	{
		count++;
		stack = stack -> next;
	}
	return count;
}

void	ft_lstadd_front (t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

int	get_pos (t_stack **list, t_stack *node)
{
	int pos;
	t_stack *aux;

	pos = 1;
	aux = *list;
	while(aux != NULL)
	{
		if (aux == node)
			break;
		pos++;
		aux = aux -> next;
	}
	return pos;
}
