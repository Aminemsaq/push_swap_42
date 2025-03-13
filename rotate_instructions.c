#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	top_node = stack->top;
	second_node = top_node->next;
	stack->top = second_node;
	top_node->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = top_node;
	index_stack(stack);
	printf("ra\n");
}

void	rb(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	top_node = stack->top;
	second_node = top_node->next;
	stack->top = second_node;
	top_node->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = top_node;
	index_stack(stack);
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);

	index_stack(stack_a);
	index_stack(stack_b);

	printf("rr\n");
}