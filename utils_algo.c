#include "push_swap.h"

void sort_two(t_stack *stack)
{
    if(stack->top->value > stack->bottom->value)
        sab(stack);
}

void sort_three(t_stack *a)
{
    if (a->top->value > a->top->next->value && a->top->value > a->top->next->next->value)
        rab(a);
    if (a->top->next->value > a->top->value && a->top->next->value > a->top->next->next->value)
        rrab(a);
    if (a->top->value > a->top->next->value)
        sab(a);
}