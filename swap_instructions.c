#include "push_swap.h"

void sa(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *first = stack->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;

    stack->top = second;
}

void sb(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *first = stack->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;

    stack->top = second;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
