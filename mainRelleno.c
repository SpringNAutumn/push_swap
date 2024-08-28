/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainRelleno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin-m <gmarin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:20:58 by gmarin-m          #+#    #+#             */
/*   Updated: 2024/08/28 19:27:37 by gmarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
t_stack *stackA;

stackA = NULL;
rellenar_stacks(&stackA, argv);
smallSorting(&stackA);

return (0);
}