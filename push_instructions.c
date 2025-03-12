#include "push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b || !stack_b->top)
        return;
    
    t_node *node_push;

    node_push = stack_b->top;
    stack_b->top = node_push->next;
    if (stack_b->top)
        stack_b->top->prev = NULL;
    else
        stack_b->bottom = NULL;
    
    node_push->next = stack_a->top;
    if (stack_a->top)
        stack_a->top->prev = node_push;
    else
        stack_a->bottom = node_push;

    node_push->prev = NULL;
    stack_a->top = node_push;
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_a->top)
        return;
    
    t_node *node_push;

    node_push = stack_a->top;
    stack_a->top = node_push->next;
    if (stack_a->top)
        stack_a->top->prev = NULL;
    else
        stack_a->bottom = NULL;
    
    node_push->next = stack_b->top;
    if (stack_b->top)
        stack_b->top->prev = node_push;
    else
        stack_b->bottom = node_push;

    node_push->prev = NULL;
    stack_b->top = node_push;
}