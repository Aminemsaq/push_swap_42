#include "push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b || !stack_b->top)
        return;

    t_node *node_push = stack_b->top;
    stack_b->top = node_push->next;

    node_push->next = stack_a->top;
    stack_a->top = node_push;

    stack_a->size++;
    stack_b->size--;
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_a->top)
        return;

    t_node *node_push = stack_a->top;
    stack_a->top = node_push->next;

    node_push->next = stack_b->top;
    stack_b->top = node_push;

    stack_b->size++;
    stack_a->size--;
}