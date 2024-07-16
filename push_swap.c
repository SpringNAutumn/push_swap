/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/16 18:47:58 by gmarin-m         ###   ########.fr       */
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
	else
		argv = randomlistnum(1000);

	push_b(&stack_A,&stack_B);
	push_b(&stack_A,&stack_B);
	bigAlgo(&stack_A, &stack_B);
	smallSorting(&stack_A);
	
	while(stack_B -> content != getMax(&stack_B))
		rotate_b(&stack_B);
	
	printf("stack B: \n");
	// imprimir stack B.
	ft_lstiter(stack_B,printing);
	printf("stack A: \n");
	// imprimir stack A
	ft_lstiter(stack_A,printing);
	
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
*/

t_stack	*getRightPos (int num, t_stack **stack)
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
		aux = aux -> next;
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
	if (node -> content < getMin(stack))
		cost = get_pos(stack, getMaxnode(stack)) - 1;
	 else 
	 	cost = get_pos(stack, getRightPos(node -> content, stack)) - 1;
	return cost;
}

int calculateCostA (t_stack **stack, t_stack *node)
{
	int cost;
	cost = get_pos(stack,node);
	return cost;
}

// No siempre encima del inmediatamente menor al numero, 
// Dado que si es un nuevo minimo tiene que ir encima del maximo. 
void moveBcheaperNode (t_stack **stackB, t_stack *node)
{
	if (node -> content < getMin(stackB))
	{
		while(*stackB != getMaxnode(stackB))
			printf("%s", rotate_b(stackB));
	}
	else while(*stackB != getRightPos(node -> content, stackB))
			printf("%s", rotate_b(stackB));
}

void moveinAandToB (t_stack **stackA, t_stack **stackB, t_stack *node)
{
	while(*stackA != node)
		printf("%s", rotate_a(stackA));
	if (*stackA == node)
		printf("%s", push_b(stackA, stackB));
}

void bigAlgo(t_stack **stackA, t_stack **stackB)
{
	t_stack *aux;
	t_stack *cheaperNode;
	
	int cost = 0;
	aux = *stackA;
	int currentMinCost = __INT_MAX__;
	
	while (ft_lstsize(*stackA) > 3)
	{
		cheaperNode = *stackA;
		while (aux)
		{
			cost = calculateCostA(stackA, aux);
			cost += calculateCostB(stackB, aux);
			if (cost < currentMinCost)
			{
				currentMinCost = cost;
				cheaperNode = aux;
			}
			aux = aux -> next;
		}
		moveBcheaperNode(stackB, cheaperNode);
		moveinAandToB(stackA,stackB,cheaperNode);
	}
}

int		getOrder(t_stack **stack)
{
	t_stack *aux = *stack;
	int adevolver = 0;
	while (aux -> next)
	{
		if (aux -> content > aux -> next -> content)
			adevolver = 1;
		aux = aux -> next;
	}
	return adevolver;
}

t_stack *getMaxnode(t_stack **stack)
{
	t_stack *aux;

	aux = *stack;
	while (aux -> content != getMax(stack) && aux)
		aux = aux -> next;
	return aux;
}
