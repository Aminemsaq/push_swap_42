#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*current;

	i = 0;
	if (!stack || stack->size == 0)
		return (NULL);
	arr = malloc(stack->size * sizeof(int));
	if (!arr)
		return (NULL);
	current = stack->top;
	while (i < stack->size)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack_sorted(t_stack *stack)
{
	int		*sorted_values;
	int		i;
	t_node	*current;

	if (!stack || stack->size == 0)
		return ;
	sorted_values = stack_to_array(stack);
	if (!sorted_values)
		return ;
	bubble_sort(sorted_values, stack->size);
	i = 0;
	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == sorted_values[i])
			{
				current->index_sorted = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sorted_values);
}

void	index_stack(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (!stack || stack->size == 0)
		return ;
	i = 0;
	current = stack->top;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}


void	print_stack_with_index(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	printf("Stack (value, index): ");
	while (current)
	{
		printf("(%d, %d, %d) ", current->value, current->index, current->index_sorted);
		current = current->next;
	}
	printf("\n");
}

