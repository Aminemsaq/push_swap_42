#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;
	int		value;

	if (!stack->top)
		return (-1);
	if (!stack->top->next)
	{
		value = stack->top->value;
		free(stack->top);
		stack->top = NULL;
	}
	else
	{
		current = stack->top;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		value = current->value;
		free(current);
		prev->next = NULL;
	}
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	while (stack->top)
		pop(stack);
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node *current = stack->top;
	printf("Stack: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}