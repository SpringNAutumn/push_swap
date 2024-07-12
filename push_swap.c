/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/11 17:24:02 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_stack *stack_A;
	t_stack *stack_B;

	stack_A = NULL;
	stack_B = NULL;
	if (argc > 1)
		rellenar_stacks(&stack_A, argv);
/*
	si stack es mayor a 3
	->>>
*/
	// move to B two elements
	while (ft_lstsize(stack_A) > 0)
	{
		while (stack_A != NULL)
		{
			int current_less_costly = __INT_MAX__;
			t_stack *aux;
			t_stack *nodetmove;
			int cost = 0;
			
			aux = stack_A;
			nodetmove = aux;
			while(aux)
			{
				cost = calculateCostA(stack_A, aux);
				cost += calculateCostB(stack_B,aux);
				if (cost < current_less_costly)
				{
					current_less_costly = cost;
					nodetmove = aux;
				}
				aux = aux -> next;
			}
			movingA(nodetmove,stack_A, stack_B);
			movingB();
			push_b();
		}

		// cuando están ordenados en B, pasamos todo hasta que B esta vacío.
	}
    return (0);
}

void printing (int content)
{
    printf("%d\n", content);
}

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

t_stack *getRightPos (int num, t_stack **stack)
{
	t_stack *nodomin;
	t_stack *aux;
	int diff;
	int currentDif = __INT_MAX__;
	
	aux = *stack;
	nodomin  = aux;
	while(aux != NULL)
	{
		if(aux -> content < num)
		{
			diff = num - aux -> content;
			if (diff < currentDif)
			{
				currentDif = diff;
				nodomin = aux;
			}
		}
		aux = aux ->next;
	}
	return nodomin;
}

int getMax (t_stack **stack)
{
	int max;
	t_stack *aux;

	aux = *stack;
	max = aux -> content;
	while(aux -> next)
	{
		if (aux -> content > max)
			max = aux -> content;
	
	aux = aux -> next;
	}
	return max;
}

int getMin (t_stack **stack)
{
	int min;
	t_stack *aux;

	aux = *stack;
	min = aux -> content;
	while(aux != NULL)
	{
		if (aux -> content < min)
			min = aux -> content;
	
		aux = aux -> next;
	}
	return min;
}

int calculateCostB (t_stack **stack, t_stack *node)
{
	int cost;

	cost = 0;
	if (get_pos(stack, getRightPos(node -> content, stack)) <= ((ft_lstsize(*stack) / 2)))
		cost = get_pos(stack, getRightPos(node -> content, stack)) - 1;
	else
		cost = ft_lstsize(*stack) - get_pos(stack, getRightPos(node -> content, stack)) + 1;
	return cost;
}

int calculateCostA (t_stack **stack, t_stack *node)
{
	int cost;

	cost = 0;
	if(get_pos(stack, node) <= (ft_lstsize(stack)) / 2)
		cost = get_pos(stack,node) - 1;
	else
		ft_lstsize(stack) - get_pos(stack,node) + 1;
	
	return cost;
}


void moveB (t_stack **stackA, t_stack **stackB, t_stack *node)
{
	if (get_pos(stackA, node) < (ft_lstsize(stackA) / 2))
		while(*stackA != node)
			rotate_a(stackA);
	else if (get_pos(stackA,node) > (ft_lstsize(stackA) / 2))
		while (*stackA != node)
			reverse_rotate_a(stackA);
	if (stackA == node)
		push_b(stackA,stackB);		
}


void moveA (t_stack **stackA, t_stack **stackB, t_stack *node)
{
	if (get_pos(stackA, node) < (ft_lstsize(stackA) / 2))
		while(*stackA != node)
			rotate_a(stackA);
	else if (get_pos(stackA,node) > (ft_lstsize(stackA) / 2))
		while (*stackA != node)
			reverse_rotate_a(stackA);
	if (stackA == node)
		push_b(stackA,stackB);		
}

void bigAlgo(t_stack **stackA, t_stack **stackB)
{
	t_stack *aux;
	
	aux = *stackA;
	int cost = 0;
	
	while (*stackA && isOrder(*stackA) == 1)
	{
		int currentMinCost = __INT_MAX__;
		while (aux)
		{
			cost = calculateCostA(stackA, aux);
			cost += calculateCostB(stackB, aux);
			if (currentMinCost > cost)
				currentMinCost = cost;
			aux = aux -> next;	
		}
	// se entiende que se ha alcanzado el nodo con el menor coste posible.
	// se mueve el nodo al principio de la lista de A, 

	
	}
}
