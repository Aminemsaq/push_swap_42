#include "push_swap.h"

void	push_stack_a(t_data *data, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		push(stack_a, data->numbers_int[i]);
		i++;
	}
}
void	init_push_swap(t_data data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return ;

	push_stack_a(&data, stack_a);

	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_four_five(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);

	print_stack(stack_a);

	free_stack(stack_a);
	free_stack(stack_b);
}


