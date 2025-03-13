#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->index == 0)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->index;
	b = stack->top->next->index;
	c = stack->top->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
		sa(stack), rra(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
		sa(stack), ra(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
}
