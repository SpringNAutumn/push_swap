/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/07/02 22:21:15 by gmarin-m         ###   ########.fr       */
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

	ft_lstiter(stack_A, printing);

	printf("aqui llegamos");
	fflush(stdout);
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
	// nos devuelve el stackA ordenado en B :o
	//sleep(20);
	sortingAlgorith(&stack_A, &stack_B);
	//printf("holaquetal");
	ft_lstiter(stack_A, printing);
    return (0);
}

void printing (int content)
{
    printf("%d\n", content);
}

int getOrder(t_stack **stack)
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
				{
					reverse_rotate_a(stackA);
					printf("operacion \n");
					ft_lstiter(*stackA, printing);
				}
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