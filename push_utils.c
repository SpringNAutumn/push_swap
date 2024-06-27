/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:53:30 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/06/27 17:02:36 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// incluir atoi, operaciones de listas. 

/*
int ft_matoi(char *nptr)
{
    // convertir el numero pasado a int.
    
    while (*nptr)
    {

        
    } 




    return ();
}
*/

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	o;

	o = 1;
	i = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-')
		o = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i ++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i ++;
	}
	return (res * o);
}
