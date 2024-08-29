#include "push_swap.h"

int main (int argc, char* argv[])
{

t_stack **stackA;

stackA = NULL;
// pasos para comprobar.  
	rellenar_stacks(stackA, argv);

 printf ("imprimiendo lista");
 // imprimir stack;
 ft_lstiter(*stackA, printing);
}

void rellenar_stacks(t_stack **stack, char *nums[])
{
	int i;
	t_stack *add;

	i = 1;
	if(!stack)
		return ;

	// mientras haya numeros y no estén ya metidos. 
	while(nums[i] && isNotInStack(stack, ft_atoi(nums[i])) == 1)
	{
		add = ft_lstnew(ft_atoi(nums[i]));
		if(!(*stack))
			*stack = add;
		else
			ft_lstadd_back(&(*stack), add);
		i++;
	}
}