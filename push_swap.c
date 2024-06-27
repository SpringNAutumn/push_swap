/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/27 18:36:28 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// funcion base, recibe como parámetros la lista de stack a ordenar.

int main (int argc, char *argv[])
{
    // empezamos con dos listas que representan los stacks.
    int i = 0;
    t_list *stackA;
	int *num;
    //t_list stackB;
	num = malloc(sizeof(int));

    // vamos asignando al stackA todos los argumentos pasados como parámetro.
    while(argv[i])
    {
		
		printf("el numero de parametros %d", argc);
        *num = ft_atoi(argv[++i]);

		t_list *añadir = ft_lstnew(num);
        ft_lstadd_back(&stackA, añadir);
        ft_lstiter(stackA, printing);
    }

	free(num);
    return (0);
}

void printing (void *content)
{
    printf("%d", *(int*)content);
}