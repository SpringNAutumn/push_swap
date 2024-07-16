/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:53:30 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/16 19:09:00 by gmarin-m         ###   ########.fr       */
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

char** randomlistnum(int size)
{
	int i = 0;
	if (size <= 0) return NULL;
	int j = 0;
	char **stringnums = malloc (size * sizeof(char*));
	if (stringnums == NULL) return NULL;
	// allocar memoria también a cada digito. y controlar la asignacion si no se ha asignado
	// correctamente desalocar la memoria.
	while(stringnums[i])
	{
		stringnums[i] = malloc (5 * sizeof(char));
		if (stringnums[i])
		{
			while (j < i)
			{
				free(stringnums[j]);
				j++;
			}
			free(stringnums);
		}
		return NULL;
		stringnums[i] = ft_itoa(rand() % 1000);
		if (!stringnums[i+1])
			stringnums[i] = "\0";
		i ++;
	}
	return stringnums;
}
// A BORRAR!!
char	*ft_itoa(int n)
{
	int			cont;
	char		*str;
	long int	ni;

	ni = n;
	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont ++;
	}
	str = mallockin(&cont, ni);
	if (!str)
		return (0);
	str[cont--] = '\0';
	if (ni < 0)
		ni = -ni;
	if (ni == 0)
		str[0] = '0';
	while (ni != 0)
	{
		str[cont--] = (ni % 10) + '0';
		ni = ni / 10;
	}
	return (str);
}

char	*mallockin(int *cont, long int n)
{
	char	*str;

	if (n < 0)
	{
		str = malloc (sizeof (char) * (*cont + 2));
		if (!str)
			return (0);
		str[0] = '-';
		*cont += 1;
	}
	else
	{
		str = malloc (sizeof (char) * (*cont + 1));
		if (!str)
			return (0);
	}
	return (str);
}
