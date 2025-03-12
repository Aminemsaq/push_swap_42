#include "push_swap.h"

void push_stack_a(Data *data, t_stack *stack_a)
{
	int i = 0;

	while (i < data->size)
	{
		push(stack_a, data->numbers_int[i]);
		i++;
	}
}
void init_push_swap(Data data)
{
	t_stack *stack_a = init_stack();
	if(!stack_a)
		return ;
	
	push_stack_a(&data, stack_a);
	print_stack(stack_a);
	rab(stack_a);
	print_stack(stack_a);
	rrab(stack_a);
	print_stack(stack_a);
	free_stack(stack_a);
}