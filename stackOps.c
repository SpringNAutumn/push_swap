/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackOps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:02:17 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/28 22:02:46 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

char *swap_a (t_stack **stackA)
{   
    t_stack *aux;
    t_stack *first;
    int numaux;


    first = stackA;
    numaux = 0;
    aux = *stackA;
    if(!stackA || aux -> next == NULL)
        return (NULL);
    else
    {
        *aux = *aux -> next;
        numaux = aux -> content;
        
        aux ->content = first -> content;
        first -> content = numaux;
    }
    
    return ("sa");
}

char *swap_b (t_stack **stackB)
{
    t_stack *aux;
    t_stack *first;
    int numaux;


    first = stackB;
    numaux = 0;
    aux = *stackB;
    if(!stackB || aux -> next == NULL)
        return (NULL);
    else
    {
        *aux = *aux -> next;
        numaux = aux -> content;
        
        aux ->content = first -> content;
        first -> content = numaux;
    }
    return ("sb");
}

char *swap_ab (t_stack **stackA, t_stack **stackB)
{
    t_stack *aux;
    t_stack *first;
    int numaux;

    first = stackB;
    numaux = 0;
    aux = *stackB;
    if(!stackB || aux -> next == NULL)
        return (NULL);
    else
    {
        *aux = *aux -> next;
        numaux = aux -> content;
        
        aux ->content = first -> content;
        first -> content = numaux;
    }
    
    first = stackA;
    numaux = 0;
    aux = *stackA;
    if(!stackA || aux -> next == NULL)
        return (NULL);
    else
    {
        *aux = *aux -> next;
        numaux = aux -> content;
        
        aux ->content = first -> content;
        first -> content = numaux;
    }
    return ("ss");
}

char *push_a (t_stack **stackA, t_stack **stackB)
{
    if (!stackB)
        return(NULL);
    else
        ft_lstadd_front(&stackA,stackB);
    return ("pa");
}

char *push_b (t_stack **stackA, t_stack **stackB)
{
    if(!stackA)
        return(NULL);
    else
        ft_lstadd_front(&stackB, stackA);
    return ("pb");
}
*/

// movemos el puntero hasta que llega a null pero intentamos leer un null
char *rotate_a (t_stack **stackA)
{

    if(stackA == NULL || *stackA == NULL ||(*stackA) ->next == NULL)
        return ("ra");

    t_stack *aux;
    t_stack *first;
    aux = *stackA;
    first = *stackA;

    while (aux -> next)
        aux = aux -> next;
    
    *stackA = first -> next;
    aux -> next = first;
    first -> next = NULL; 

    return ("ra");
}

char *rotate_b (t_stack **stackB)
{
    int num;
    
    num = (*stackB) ->content;
    while (*stackB)
    {
        *stackB = (*stackB) ->next;
    }
    (*stackB) ->content = num;

    return ("rb");
}

char *rotate_ab (t_stack **stackA, t_stack **stackB)
{
      int num;
    
    num = (*stackA) ->content;
    while (*stackA)
    {
        *stackA = (*stackA) ->next;
    }
    (*stackA) ->content = num;

       num = (*stackB) ->content;
    while (*stackB)
    {
        *stackB = (*stackB) ->next;
    }
    (*stackB) ->content = num;

    return ("rr");    
}
/*

char *reverse_rotate_a (t_stack **stackA)
{
    t_stack *ultimo;
    while((*stackA) -> next)
    {
        *stackA = (*stackA) -> next;
    }
      if(!(*stackA) -> next -> next)
           ultimo = stackA;

    (*stackA) -> next = *stackA;
    ultimo -> next = NULL;
    
    return ("rra");
}

char *reverse_rotate_b(t_stack **stackB)
{

    t_stack *ultimo;
    while((*stackB) -> next)
    {
        *stackB = (*stackB) -> next;
    }
      if(!(*stackB) -> next -> next)
           ultimo = stackB;

    (*stackB) -> next = *stackB;
    ultimo -> next = NULL;
    
    return ("rra");
}

char *reverse_rotate_ab(t_stack **stackA, t_stack **stackB)
{
    t_stack *ultimo;
    while((*stackA) -> next)
    {
        *stackA = (*stackA) -> next;
    }
      if(!(*stackA) -> next -> next)
           ultimo = stackA;

    (*stackA) -> next = *stackA;
    ultimo -> next = NULL;

    while((*stackB) -> next)
    {
        *stackB = (*stackB) -> next;
    }
      if(!(*stackB) -> next -> next)
           ultimo = stackB;

    (*stackB) -> next = *stackB;
    ultimo -> next = NULL;
    
    return ("rrr");
}
*/
