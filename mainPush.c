/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainPush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:06:55 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/27 18:21:59 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// vamos a utilizar las listas enlazadas 
// para crear los movimientos del stack


// creamos una lista enlazada con numeros aleatorios
int main (void)
{
    int *num = malloc(sizeof(int));
    if (!num)
        return 1;

    *num = 42;
    t_list *lista = ft_lstnew(num);
    t_list *lista2 = ft_lstnew(num);

    ft_lstadd_back(&lista, lista2);

    ft_lstiter(lista, printing);
    free(num);
    
    return (0);
}

void printing(void *content)
{
    
    printf("%d\n", *(int *)content);
    
}


