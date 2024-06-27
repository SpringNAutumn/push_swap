#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void printing(void *content);

// definimos el struct para la lista enlazada

typedef struct s_stack
{
	int			    content;
	struct s_stack	*next;
}	t_stack;