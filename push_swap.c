/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/15 18:47:20 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_stack *stack_A;
	t_stack *stack_B;

	char *arrelenar[] = {"0", "10", "5", "4", "1" , NULL};

	stack_A = NULL;
	stack_B = NULL;
	if (argc > 1)
		rellenar_stacks(&stack_A, argv);

	rellenar_stacks(&stack_B,arrelenar);
	bigAlgo(&stack_A, &stack_B);

	printf("resultado de mover en stackB el cheaper node \n");
	
	ft_lstiter(stack_B,printing);
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


Movemos dos elementos a stackB, iteramos A, calculamos coste para num en funcion
de la posicion.

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


// coste de mover el nodo especificado, (el 1) en el stack b, esto es poner el inmediatamente menor arriba del todo.
int calculateCostB (t_stack **stack, t_stack *node)
{
	int cost;
	printf("coste de mover el nodo especificado, (el 1) en el stack b %d ", get_pos(stack, getRightPos(node -> content, stack)));
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
	if(get_pos(stack, node) <= (ft_lstsize(*stack)) / 2)
		cost = get_pos(stack,node) - 1;
	else
		cost = ft_lstsize(*stack) - get_pos(stack,node) + 1;
	return cost;
}

void moveBcheaperNode (t_stack **stackB, t_stack *node)
{
	printf("valor del nodo: %d \n" , node -> content);
	printf("posicion del nodo que tenemos que mover : %d ", get_pos(stackB,getRightPos(node ->content, stackB)));
	if (get_pos(stackB,getRightPos(node ->content, stackB)) < (ft_lstsize(*stackB) / 2))
		while(*stackB != getRightPos(node -> content, stackB))
			printf("iprimiendo: %s", rotate_b(stackB));
	else if (get_pos(stackB,getRightPos(node ->content, stackB)) > (ft_lstsize(*stackB) / 2))
		while (*stackB != getRightPos(node -> content, stackB))
			printf(" impriminendo: %s", reverse_rotate_b(stackB));
}

void moveinAandToB (t_stack **stackA, t_stack **stackB, t_stack *node)
{

printf("valor del nodo: %d" , node -> content);
	if (get_pos(stackA, node) < (ft_lstsize(*stackA) / 2))
		while(*stackA != node)
			rotate_a(stackA);
	else if (get_pos(stackA, node) > (ft_lstsize(*stackA) / 2))
		while (*stackA != node)
			reverse_rotate_a(stackA);
	if (*stackA == node)
		push_b(stackA, stackB);
}

void bigAlgo(t_stack **stackA, t_stack **stackB)
{
	t_stack *aux;
	
	
	int cost = 0;
	push_b(stackA,stackB);
	push_b(stackA,stackB);
	aux = *stackA;
	ft_lstiter(*stackB,printing);
	int currentMinCost = __INT_MAX__;
	t_stack *cheaperNode;

	cheaperNode = *stackA;
	int numero = 3;
	while (numero > 0)
	{
		while (aux)
		{
			cost = calculateCostA(stackA, aux);
			cost += calculateCostB(stackB, aux);
			
		
			printf("coste: %d, valor variable auxiliar: %d", cost , aux -> content);
			if (cost < currentMinCost)
			{
				currentMinCost = cost;
				cheaperNode = aux;
				printf("nodo mas barato: %d" , cheaperNode -> content);
			}
			aux = aux -> next;
		}
		printf("nodo mas barato: %d" , cheaperNode -> content);
		//printf ("valor del cheaper node: %d , puntero del cheaper node: %p", cheaperNode -> content , cheaperNode);
		moveBcheaperNode (stackB, cheaperNode);
		//moveinAandToB(stackA,stackB,cheaperNode);

		numero --;	
	}
}

/*
		  5
		  4
		  1
		  10
          
		  
	
	2
	10
	2
	9
	3
	8
   21
    7
   50
   11
   
*/