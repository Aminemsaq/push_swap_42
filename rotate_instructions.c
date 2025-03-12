#include "push_swap.h"

void rab(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *top_node = stack->top;
    t_node *second_node = top_node->next;

    stack->top = second_node;
    stack->top->prev = NULL;

    top_node->next = NULL;

    if (stack->bottom) {
        stack->bottom->next = top_node;
        top_node->prev = stack->bottom;
    }

    stack->bottom = top_node;
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
    rab(stack_a);
    rab(stack_b);
}
