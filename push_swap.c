/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/30 21:28:57 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
    t_stack *stackA;
    t_stack *stackB;

    stackA = NULL;
    stackB = NULL;
    printf("el numero de parametros %d \n", argc);
    
    rellenar_stacks(&stackA, argv);

    printf("Exec sa \n");
    swap_a(&stackA);

    printf("Exec pb pb pb \n");

    push_b(&stackA, &stackB);
    push_b(&stackA, &stackB);
    push_b(&stackA, &stackB);

      printf("STACK B: \n");
    if(stackB)
       ft_lstiter(stackB, printing);
    printf("STACK A: \n");
    if(stackA)
        ft_lstiter(stackA, printing);

    printf("Exec ra rb \n");
    rotate_a(&stackA);
    rotate_b(&stackB);


      printf("STACK B: \n");
    if(stackB)
       ft_lstiter(stackB, printing);
    printf("STACK A: \n");
    if(stackA)
        ft_lstiter(stackA, printing);
    
    printf("Exec rra rrb \n");
    reverse_rotate_a(&stackA);
    reverse_rotate_b(&stackB);

      printf("STACK B: \n");
    if(stackB)
       ft_lstiter(stackB, printing);
    printf("STACK A: \n");
    if(stackA)
        ft_lstiter(stackA, printing);

    printf("Exec sa \n");
    swap_a(&stackA);

      printf("STACK B: \n");
    if(stackB)
       ft_lstiter(stackB, printing);
    printf("STACK A: \n");
    if(stackA)
        ft_lstiter(stackA, printing);

    printf("Exec pa pa pa \n");
    push_a(&stackA,&stackB);
    push_a(&stackA,&stackB);
    push_a(&stackA,&stackB);
    
    printf("STACK B: \n");
    if(stackB)
       ft_lstiter(stackB, printing);
    printf("STACK A: \n");
    if(stackA)
        ft_lstiter(stackA, printing);

    return (0);
}

void printing (int content)
{
    printf("%d\n", content);
}

void rellenar_stacks(t_stack **stack, char *nums[])
{
    int i;
    
    if(!stack)
        return ;
        
    i = 1;
    while(nums[i])
    {
		t_stack *añadir = ft_lstnew(ft_atoi(nums[i]));
          
        if(!(*stack))
            *stack = añadir;
        else
            ft_lstadd_back(&(*stack), añadir);
        i++;
    }
}