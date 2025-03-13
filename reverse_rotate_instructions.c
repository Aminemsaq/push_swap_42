#include "push_swap.h"

void rra(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *prev = NULL;
    t_node *current = stack->top;

    while (current->next)
    {
        prev = current;
        current = current->next;
    }

    if (prev)
        prev->next = NULL;

    current->next = stack->top;
    stack->top = current;
}

void rrb(t_stack *stack)
{
    if (!stack || !stack->top || stack->size < 2)
        return;

    t_node *prev = NULL;
    t_node *current = stack->top;

    while (current->next)
    {
        prev = current;
        current = current->next;
    }

    if (prev)
        prev->next = NULL;

    current->next = stack->top;
    stack->top = current;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}