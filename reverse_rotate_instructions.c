#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
	index_stack(stack);
	printf("rra\n");
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
	index_stack(stack);
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);

	index_stack(stack_a);
	index_stack(stack_b);

	printf("rrr\n");
}