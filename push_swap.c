/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/04 19:54:48 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_stack *stack_A;
	//t_stack *stack_B;

	stack_A = NULL;
	//stack_B = NULL;
	
	if (argc > 1)
		rellenar_stacks(&stack_A, argv);


// comprobacion de funciones
	
	
	printf("posicion inicial %p \n" , (void*) (stack_A -> next -> next));
		printf("posicion inicial %p \n" , (void*) &(stack_A));
	
	printf("posicion %d \n" , get_pos(&stack_A, stack_A -> next -> next));
	//printf("%d", getMax(&stack_A));
	//printf("%d", getMin(&stack_A));
	//printf ("%d", getRightPos(4,stack_B));
	/*
	if (argc <=3)
		smallSorting(&stack_A);
	else 
		sortingAlgorithNoTmp(&stack_A, &stack_B);
     */
    return (0);
}

void printing (int content)
{
    printf("%d\n", content);
}
/*
int isOrder(t_stack **stack)
{
    t_stack *aux;

    aux = *stack;
    while(aux -> next)
    {
        if ((aux) -> content > aux -> next -> content)
            return 1;
        aux = aux -> next;
    }
    return 0;
}
*/

void rellenar_stacks(t_stack **stack, char *nums[])
{
    int i;
    
    if(!stack)
        return ;
        
    i = 1;
    while(nums[i])
    {
		t_stack *anadir = ft_lstnew(ft_atoi(nums[i]));
          
        if(!(*stack))
            *stack = anadir;
        else
            ft_lstadd_back(&(*stack), anadir);
        i++;
    }
}
/*
void smallSorting (t_stack **stackA)
{
	if(!stackA || !(*stackA))
		return ;
	
	while (getOrder(stackA) != 0)
	{
		if (ft_lstsize(*stackA) == 2)
		{
			if ((*stackA) -> content > (*stackA) -> next ->content)
				swap_a(stackA);
		}
		else if (ft_lstsize(*stackA) == 3)
			{
				if ((*stackA) -> content > (*stackA) -> next -> content)
					swap_a(stackA);
				if ((*stackA) -> next -> content > (*stackA) -> next -> next -> content)
					printf("%s",reverse_rotate_a(stackA));
			}
	}
}

void sortingAlgorithWithTmp(t_stack **stackA, t_stack **stackB)
{
	t_stack *currele;
	while (*stackA)
	{
		currele = temPop(stackA);
		while ((*stackB) && (*stackB) -> content > currele -> content)
		{
			printf("%s",push_a(stackA, stackB));
		}
		currele -> next = (*stackB);
		*stackB = currele;
	}
	while(*stackB)
		printf("%s",push_a(stackA,stackB));
}
*/
/*
void sortingAlgorithNoTmp(t_stack **stackA, t_stack **stackB)
{
	while (*stackA)
	{
		while ((*stackB) && (*stackB) -> content > (*stackA) -> content)
		{
			printf("%s",push_a(stackA, stackB));
			printf("%s",swap_a(stackA));
		}
		printf("%s",push_b(stackA,stackB));
	}
	while(*stackB)
		printf("%s",push_a(stackA,stackB));
}

t_stack *temPop(t_stack **stack)
{
	t_stack *aux;

	if(!stack || !(*stack))
		return (NULL);

	aux = *stack;
	*stack = (*stack) -> next;
	aux -> next = NULL;
	return (aux);
}
*/
/* TODO 

	Movemos dos elementos a stackB, iteramos A, calculamos coste para num en funcion
	de la posicion 

*/
/*
void goodSort (t_stack **stackA, t_stack **stackB)
{

	t_stack *auxiA;
	t_stack *auxiB;


	auxiA = *stackA;
	auxiB = *stackB;
	while (isOrder(*stackA) == 1 || ft_lstsize(*stackA) > 3)
	{
		if(!*stackB)
		{
			push_b(stackA, stackB);
			push_b(stackA, stackB);
		}

		while(auxiA -> next)
			{
				// para el elemento calculamos coste guardamos el resultado,
				// vemos cual es el menor resultado,
						// ejecutamos operacion ->>> 
				
					
			
			}
	}
}
*/
// cuando pusheamos un numero que no es el nuevo minimo o nuevo maximo 
// (el cual se pone encima del maximo del stackB),
// tenemos que ponerlo por encima del inmediatamente menor al numero.
// podemos o devolver la posicion del nodo en el stack, o devolver el nodo,
// si devovlemos la posicion, se devuelve la posicion del currentMin. 

t_stack *getRightPos (int num, t_stack **stack)
{
	int currentMin;
	t_stack *nodo;
	
	currentMin = (*stack) -> content;
	while((*stack) -> next)
	{
		if((*stack) -> content > num)
		{
			(*stack) = (*stack) -> next;
			continue;
		}
		else if ((*stack) -> content > currentMin)
		{
			currentMin = (*stack) -> content;
			nodo = *stack;
		}
		*stack = (*stack) -> next;
	}
	return nodo;
}

int getMax (t_stack **stack)
{
	int max;

	max = 0;
	while((*stack) -> next)
	{
		if ((*stack) -> content > max)
			max = (*stack) -> content;
	
	(*stack) = (*stack) -> next;
	}
	return max;
}

int getMin (t_stack **stack)
{
	int min;

	min = 0;
	while((*stack) -> next)
	{
		if ((*stack) -> content < min)
			min = (*stack) -> content;
	
	(*stack) = (*stack) -> next;
	}
	return min;
}
/*
int calculateCosts (t_stack **stackA, t_stack **stackB, t_stack *node)
{
	int cost;

	cost = 0;
	if (node -> content < getMin(stackB))
		cost +=2;
	else if (node -> content > getMax(stackB))
		cost ++;
	else 
	{
		if (get_pos(stackB, getRightPos(node -> content, stackB)) < (ft_lstsize(*stackB) / 2))
			cost = (get_pos(stackB, getRightPos(node -> content, stackB)) - 1);
		else
			cost = ft_lstsize(*stackB) - get_pos(stackB, getRightPos(node -> content, stackB)) - 1;
	}
	return cost;
}
*/