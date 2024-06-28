/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/28 20:23:56 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
    int i = 1;
    t_stack *stackA;

    stackA = NULL;
    printf("el numero de parametros %d", argc);
    printf("hola \n");


    
    while(argv[i])
    {
		t_stack *añadir = ft_lstnew(ft_atoi(argv[i]));
        if(!stackA)
            stackA = añadir;
        else
            ft_lstadd_back(&stackA, añadir);
        i++;
    }

    printf("operacion a comprobar %s", rotate_a(&stackA));
    // printf("operacion a comprobar %s", swap_a(stackA));
    // printf("operacion a comprobar %s", swap_a(stackA));

    
    // PARA IMPRIMIR
    if(stackA)
        ft_lstiter(stackA, printing);

    return (0);
}

void printing (int content)
{
    printf("%d\n", content);
}