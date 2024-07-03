/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/03 21:02:16 by gmarin-m         ###   ########.fr       */
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
		
	//ft_lstiter(stack_A, printing);
	
	//smallSorting(&stack_A);
	/*
	
    if (getOrder(&stack_A) == 0)
	{
        printf("el stack se ordeno correctamente \n");
		ft_lstiter(stack_A, printing);
	}
	else
	{
		printf("algo ha fallado \n");
		ft_lstiter(stack_A, printing);
	}
	*/

	if (argc <=3)
		smallSorting(&stack_A);
	else 
		sortingAlgorithNoTmp(&stack_A, &stack_B);
		
	//printf(" NUMERO OPERACIONES PARA ORDENAR EL STACK\n %d", numberOps);
	//ft_lstiter(stack_A, printing);
	//printf("numero de argumentos %d", argc);
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

void goodSort (t_stack **stackA, t_stack **stackB)
{

	t_stack *auxiA;
	t_stack *auxiB;


	auxiA = *stackA;
	auxiB = *stackB;
	while (isOrder(*stackA) == 1 || ft_lstsize(*stackA)> 3)
	{
		if(!*stackB)
			push_b(stackA, stackB), push_b(stackA,stackB);

		while(auxiA -> next)
			{
				// calcular para cada posicion del stack A el coste de meter el numero
				// en la posicion ideal en B, teniendo en cuenta que la posicion ideal es
				// la que está el numero ordenado con respecto al inmediatamente menor 				
			// before push_b
				
			

			}
	}
}

// ver los stacks como listas dobles
	// si es nuevo maximo, in

// no tenemos que encontrar la posición correcta, si lo situamos encima del 
void getRightPos (int num, t_stack **stack)
{
	int currentMax;

	currentMax = (*stack) -> content;
	while((*stack) -> next)
	{
		if (num > currentMax && (*stack) -> content > currentMax);
				currentMax = (*stack) -> content;

		*stack = (*stack) -> next;
	}
}