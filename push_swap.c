/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/08/18 16:25:25 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_stack *stack_A;
	t_stack *stack_B;
	char	**nums;
	
	stack_A = NULL;
	stack_B = NULL;
	
	srand(time(NULL));
	nums = randomlistnum(500);
	if (argc > 1)
		rellenar_stacks(&stack_A, argv);
	else
		rellenar_stacks(&stack_A, nums);

	push_b(&stack_A,&stack_B);
	push_b(&stack_A,&stack_B);
	bigAlgo(&stack_A, &stack_B);
	smallSorting(&stack_A);
	
	while(stack_B -> content != getMax(&stack_B))
		write(1, rotate_b(&stack_B), 3);

	movetoA(&stack_A, &stack_B);
	 //while(ft_lstsize(stack_B) > 0)
	 	//push_a(&stack_A, &stack_A);
	//printf("stack B: \n");
	//ft_lstiter(stack_B,printing);
	//printf("stack A: \n");
	// // imprimir stack A
 	//ft_lstiter(stack_A,printing);
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
	t_stack *add;

	i = 1;
	if(!stack)
		return ;
	while(nums[i])
	{
		add = ft_lstnew(ft_atoi(nums[i]));
		if(!(*stack))
			*stack = add;
		else
			ft_lstadd_back(&(*stack), add);
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
				write(1, swap_a(stackA), 3);
		}
		else if (ft_lstsize(*stackA) == 3)
			{
				if ((*stackA) -> content > (*stackA) -> next -> content)
					write(1, swap_a(stackA), 3);
				if ((*stackA) -> next -> content > (*stackA) -> next -> next -> content)
					write(1, reverse_rotate_a(stackA), 4);
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
	while(aux)
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
	{
			if(get_pos(stack, getMaxnode(stack)) <= ft_lstsize(*stack) / 2 + 1)
				cost = get_pos(stack, getMaxnode(stack)) - 1;
			else
			{
				if (isEven(stack) == 1)
					cost = (ft_lstsize(*stack) - get_pos(stack, getMaxnode(stack))) + 1;
				else	
					cost = (ft_lstsize(*stack) - get_pos(stack, getMaxnode(stack))) + 2;
			}
	}
	else
	{
		if (get_pos(stack, getRightPos(node -> content, stack)) <= ft_lstsize(*stack) / 2 + 1)
	 		cost = get_pos(stack, getRightPos(node -> content, stack)) - 1;
		else
			if (isEven(stack) == 1)
				cost = (ft_lstsize(*stack) - get_pos(stack, getRightPos(node -> content, stack))) + 1;
			else
				cost = (ft_lstsize(*stack) - get_pos(stack, getRightPos(node -> content, stack))) + 2;
	}
	return cost;
}

int calculateCostA (t_stack **stack, t_stack *node)
{
	int cost;
	if (get_pos(stack,node) <= ft_lstsize(*stack) / 2 + 1)
		cost = get_pos(stack,node);
	else
		if (isEven(stack) == 1)
			cost = ft_lstsize(*stack) - get_pos(stack,node) + 2;
		else
			cost = ft_lstsize(*stack) - get_pos(stack,node) + 3;
	return cost;
}

// en moveBcheapernode devolveremos la posicion en notacion numerica de donde se encuentra el nodo que vamos a colocar. 
// (siempre colocaremos el numero por encima)
void moveBcheaperNode (t_stack **stackB, t_stack *node)
{
	t_stack *targetB;

	if(node -> content < getMin(stackB))
		targetB = getMaxnode(stackB);
	else
		targetB = getRightPos(node -> content, stackB);
		
	if(get_pos(stackB, targetB) <= ft_lstsize(*stackB) / 2 + 1)
		while(*stackB != targetB)
		{
			write(1, rotate_b(stackB), 3);
		}
	else
		while(*stackB != targetB)
		{
			write(1, reverse_rotate_b(stackB), 4);
		}
}


void moveinAandToB (t_stack **stackA, t_stack **stackB, t_stack *node)
{
	while(*stackA != node)
	{
		if(get_pos(stackA, node) < ft_lstsize(*stackA) / 2 + 1)
			write(1, rotate_a(stackA), 3);
		else
			write(1, reverse_rotate_a(stackA), 4);
	}	
	if (*stackA == node)
		write(1, push_b(stackA, stackB), 3);
}

void bigAlgo(t_stack **stackA, t_stack **stackB)
{
	t_stack *aux;
	t_stack *cheaperNode;
	
	int cost = 0;
	//int diff;
	aux = *stackA;
	int currentMinCost;
	
	while (ft_lstsize(*stackA) > 3)
	{
		currentMinCost = 9999999;
		cheaperNode = *stackA;
		while (aux)
		{
			cost = calculateCostA(stackA, aux);
			cost += calculateCostB(stackB, aux);
			//printf("coste: %d \n" , cost);
			// imprimir lineas
			//printf("stack B: \n");
			//ft_lstiter(*stackB, printing);
			//printf("stack A: \n");
			//ft_lstiter(*stackA,printing);
			if (cost < currentMinCost)
			{
				currentMinCost = cost;
				cheaperNode = aux;
			}
			aux = aux -> next;
		//printf("el menor coste: %d , para el numero: %d \n", cost, cheaperNode -> content);
		}
		//printf("el menor coste: %d , para el numero: %d \n", currentMinCost, cheaperNode -> content);
		//printf("stack B: \n");
		// imprimir stack B. 
		//ft_lstiter(*stackB,printing);
		//printf("stack A: \n");
		// // imprimir stack A
 		//ft_lstiter(*stackA,printing);
		
		// me esta dando mas movimientos por el calculo del coste, calculamos el coste, acto seguido, ahorramos los movimientos y movemos el cheaperNode.
	
		savingmoves(cheaperNode,stackA,stackB);
		moveBcheaperNode(stackB, cheaperNode);
		moveinAandToB(stackA, stackB, cheaperNode);
		aux = *stackA;	
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

void movetoA (t_stack **stackA, t_stack **stackB)
{
	t_stack *auxA;
	t_stack *auxB;

	auxA = *stackA;
	auxB = *stackB;
	while (auxA -> next)
		auxA = auxA -> next;
		
	while (auxB)
	{
		if (auxB-> content > auxA ->content)
		{
			write (1, push_a(stackA, stackB), 3);
			auxB = *stackB;
		}
		else
		{
			if (getMin(stackA) > auxB -> content)
			{		
				write (1, reverse_rotate_a(stackA), 4);
				while (auxB)
				{
					write (1, push_a(stackA, stackB), 3);
					auxB = *stackB;
				}
				break;
			}
			write (1, reverse_rotate_a(stackA), 4);
			auxA = *stackA;
			while (auxA -> next && auxB)
				auxA = auxA -> next;
		}
	}
}


/* debuggerar*/
/*
 La logica de saving moves:
	tenemos los dos stacks, antes de mover normalmente los numeros, lo que queremos hacer es mover tanto el numero del stack A como el numero del stack b correspondiente hasta que uno de los dos 
	llegue hasta el principio del stack
*/

void	savingmoves(t_stack *cheaperNode, t_stack **stackA, t_stack **stackB)
{
	t_stack *targetB;

	if (cheaperNode -> content < getMin(stackB))
		targetB = getMaxnode(stackB);
	else
		targetB = getRightPos(cheaperNode -> content, stackB);
	
	while (*stackA != cheaperNode && *stackB != targetB)
	{
		if(((get_pos(stackA, cheaperNode) < ft_lstsize(*stackA) / 2 + 1) && 
			get_pos(stackB, targetB) <= ft_lstsize(*stackB) / 2 + 1))
			rotate_ab(stackA,stackB);
		else if(((get_pos(stackA, cheaperNode) > ft_lstsize(*stackA) / 2 + 1) && 
			get_pos(stackB, targetB) >= ft_lstsize(*stackB) / 2 + 1))
			reverse_rotate_ab(stackA,stackB);
		else
			break ;
	}
}

// el caso en el que un numero este en la mitad superior y el otro en la mitad inferior 

/*

 4	13
 6	52
 8	5
 10	6
 14	6
 20 8

*/