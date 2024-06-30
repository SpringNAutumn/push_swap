#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int			    content;
	struct s_stack	*next;
}	t_stack;

void	printing(int ontent);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
int		ft_atoi(const char *nptr);
void	ft_lstiter(t_stack *lst, void (*f)(int));
int		ft_lstsize(t_stack *stack);
void	ft_lstadd_front (t_stack **lst, t_stack *new);
char	*rotate_a (t_stack **stackA);
char	*rotate_b (t_stack **stackB);
char	*rotate_ab (t_stack **stackA, t_stack **stackB);
char	*reverse_rotate_ab(t_stack **stackA, t_stack **stackB);
char	*reverse_rotate_b(t_stack **stackB);
char	*reverse_rotate_a (t_stack **stackA);
char	*push_b (t_stack **stackA, t_stack **stackB);
char	*push_a (t_stack **stackA, t_stack **stackB);
char	*swap_ab (t_stack **stackA, t_stack **stackB);
char	*swap_b (t_stack **stackB);
char	*swap_a (t_stack **stackA);
void	rellenar_stacks(t_stack **stack, char *nums[]);
