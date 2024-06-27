/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/27 19:40:23 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// funcion base, recibe como parámetros la lista de stack a ordenar.

int main (int argc, char *argv[])
{
    // empezamos con dos listas que representan los stacks.
    int i = 0;
    t_list *stackA;
    //t_list stackB;

    // vamos asignando al stackA todos los argumentos pasados como parámetro.
    while(argv[i])
    {
		printf("el numero de parametros %d", argc);
		t_list *añadir = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(&stackA, añadir);
        i++;
    }
    ft_lstiter(stackA, printing);

    return (0);
}

void printing (void *content)
{
    printf("%d\n", *(int*)content);
}