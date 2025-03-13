#include "push_swap.h"

void ra(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *top_node = stack->top;
    t_node *second_node = top_node->next;

    stack->top = second_node;
    top_node->next = NULL;

    t_node *current = stack->top;
    while (current->next)
        current = current->next;

    current->next = top_node;
}

void rb(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *top_node = stack->top;
    t_node *second_node = top_node->next;

    stack->top = second_node;
    top_node->next = NULL;

    t_node *current = stack->top;
    while (current->next)
        current = current->next;

    current->next = top_node;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

