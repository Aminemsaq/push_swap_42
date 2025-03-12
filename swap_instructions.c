#include "push_swap.h"

void sab(t_stack *stack)
{
    if(!stack || stack->size < 2)
        return ;
    t_node *first;
    t_node *second;

    first = stack->top;
    second = first->next;

    first->next = second->next;
    if(second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    stack->top = second;

    printf("sab\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sab(stack_a);
    sab(stack_b);
}
