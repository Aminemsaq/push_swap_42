#include "push_swap.h"

void rrab(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *last_node = stack->bottom;
    t_node *second_last_node = last_node->prev;

    stack->bottom = second_last_node;
    stack->bottom->next = NULL;

    last_node->prev = NULL;
    last_node->next = stack->top;
    stack->top->prev = last_node;

    stack->top = last_node;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rrab(stack_a);
    rrab(stack_b);
}