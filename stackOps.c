/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackOps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:02:17 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/08/16 17:25:35 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *swap_a (t_stack **stackA)
{
	t_stack *first;
	t_stack *aux;

	first = *stackA;
	aux = (*stackA) -> next; 
	first -> next = first -> next -> next;
	aux -> next = first;
	*stackA = aux;
	return ("sa\n");
}

char *swap_b (t_stack **stackB)
{
	t_stack *first;
	t_stack *aux;

	first = *stackB;
	aux = (*stackB) -> next;
	first -> next = first -> next -> next;
	aux -> next = first;
	*stackB = aux;

	return ("sb\n");
}

char *swap_ab (t_stack **stackA, t_stack **stackB)
{
	t_stack *first;
	t_stack *aux;
	
	first = *stackA;
	aux = (*stackA) -> next; 
	first -> next = first -> next -> next;
	aux -> next = first;
	*stackA = aux;
	first = *stackB;
	aux = (*stackB) -> next;
	first -> next = first -> next -> next;
	aux -> next = first;
	*stackB = aux;
	return ("ss\n");
}

char *push_a (t_stack **stackA, t_stack **stackB)
{
	t_stack *primero;

	if(!stackA || !stackB || !(*stackB))
		return (NULL);

	primero = *stackB;
	*stackB = primero ->next;

	if(!(*stackA))
	{
		*stackA = primero;
		primero -> next = NULL;
	}
	else
	{
		primero -> next = *stackA;
		*stackA = primero;
	}
	return ("pa\n");
}

char *push_b (t_stack **stackA, t_stack **stackB)
{
	t_stack *primero;
	
	if(!stackB || !stackA || !(*stackA))
		return (NULL);

    primero = *stackA;
    *stackA = primero -> next;
	
	if(!*(stackB))
	{
		*stackB = primero;
		primero -> next = NULL;
	}
	else
    {
		primero -> next = *stackB;
		*stackB = primero;
	}
	return ("pb\n");
}

char *rotate_a (t_stack **stackA)
{

    if(stackA == NULL || *stackA == NULL ||(*stackA) ->next == NULL)
        return ("ra\n");

    t_stack *aux;
    t_stack *first;
    aux = *stackA;
    first = *stackA;

    while (aux -> next)
        aux = aux -> next;
    
    *stackA = first -> next;
    aux -> next = first;
    first -> next = NULL; 

    return ("ra\n");
}

char *rotate_b (t_stack **stackB)
{
    if(stackB == NULL || *stackB == NULL ||(*stackB) ->next == NULL)
        return ("rb\n");
   
   t_stack *first;
   t_stack *aux;

    aux = *stackB;
    first = *stackB;

    while (aux -> next)
	{
        aux = aux -> next;
	}
    
    aux -> next = first;
	(*stackB) = first ->next;
	first -> next = NULL;
    
    return ("rb\n");
}

char *rotate_ab (t_stack **stackA, t_stack **stackB)
{  
    if(stackB == NULL || *stackB == NULL ||(*stackB) ->next == NULL 
    || stackA == NULL || *stackA== NULL  ||(*stackA) ->next == NULL)
        return ("rr\n");
    
    t_stack *aux;
    t_stack *first;
    aux = *stackA;
    first = *stackA;

    while (aux -> next)
        aux = aux -> next;
    
    *stackA = first -> next;
    aux -> next = first;
    first -> next = NULL;

    aux = *stackB;
    first = *stackB;

    while (aux -> next -> next)
        aux = aux -> next;
    
    *stackB = aux -> next;
    (*stackB) -> next = first;
    aux -> next = NULL;

    return ("rr\n");
}

char *reverse_rotate_a (t_stack **stackA)
{

    if (!stackA || !(*stackA) || !((*stackA) -> next))
        return ("rra\n");
    
    t_stack *aux;
    t_stack *first;

    aux = *stackA;
    
    while(aux -> next -> next)
    {
        aux = aux -> next;
    }
    first = aux -> next;
    first -> next = *stackA;
    *stackA = first;
    aux -> next = NULL;

    return ("rra\n");
}

char *reverse_rotate_b(t_stack **stackB)
{
    if (!stackB || !(*stackB) || !((*stackB) -> next))
        return ("rrb\n");

    t_stack *aux;
    t_stack *first;

    aux = *stackB;
    
    while(aux -> next -> next)
    {
        aux = aux -> next;
    }
    first = aux -> next;
    first -> next = *stackB;
    *stackB = first;
    aux -> next = NULL;

    return ("rrb\n");
}

char *reverse_rotate_ab(t_stack **stackA, t_stack **stackB)
{
	if (!stackB || !(*stackB) || !((*stackB) -> next) || !stackA || !(*stackA) || !((*stackA) -> next))
		return ("rrr\n");
	t_stack *aux;
	t_stack *first;

	aux = *stackA;
	while(aux -> next -> next)
	{
		aux = aux -> next;
	}
	first = aux -> next;
	first -> next = *stackA;
	*stackA = first;
	aux -> next = NULL;
	aux = *stackB;
	while(aux -> next -> next)
	{
		aux = aux -> next;
	}
	first = aux -> next;
	first -> next = *stackB;
	*stackB = first;
	aux -> next = NULL;
	return ("rrr\n");
}
