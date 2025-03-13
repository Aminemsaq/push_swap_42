#include "push_swap.h"

void	push_stack_a(Data *data, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		push(stack_a, data->numbers_int[i]);
		i++;
	}
}
void	init_push_swap(Data data)
{
	t_stack *stack_a = init_stack();
	if (!stack_a)
		return ;
	push_stack_a(&data, stack_a);
	index_stack(stack_a);
	print_stack(stack_a);
	if (stack_a->size == 2)
		sort_two(stack_a);
	if (stack_a->size == 3)
		sort_three(stack_a);
	printf("%d\n", stack_a->top->value);
	print_stack(stack_a);
	print_stack_with_index(stack_a);
	free_stack(stack_a);
}