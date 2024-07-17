#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

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

// funciones auxiliares
int		get_pos (t_stack **list, t_stack *node);
int		getMax (t_stack **stack);
int		getMin (t_stack **stack);
int		calculateCostA (t_stack **stack, t_stack *node);
int		calculateCostB (t_stack **stack, t_stack *node);
t_stack *getRightPos (int num, t_stack **stack);
void	goodSort (t_stack **stackA, t_stack **stackB);
void	moveinAandToB (t_stack **stackA, t_stack **stackB, t_stack *node);
void	moveBcheaperNode (t_stack **stackB, t_stack *node);
void	rellenar_stacks(t_stack **stack, char *nums[]);
void	sorting (t_stack **stackA);
int		getOrder(t_stack **stack);
void	smallSorting (t_stack **stackA);
t_stack *getMaxnode(t_stack **stack);
char** 	randomlistnum(int size);

// algoritmo de odenacion malo.
void	sortingAlgorithWithTmp(t_stack **stackA, t_stack **stackB);
void	sortingAlgorithNoTmp(t_stack **stackA, t_stack **stackB);

// algoritmos buenos
void	bigAlgo(t_stack **stackA, t_stack **stackB);
void	smallSorting (t_stack **stackA);


// para tests a eliminar.
char	*ft_itoa(int n);
char	*mallockin(int *cont, long int n);
int	isNotInList(char **stack, int numero);