#include "push_swap.h"
#include "push_swap.h"

void define_chunks(t_stack *stack)
{
    int size = stack->size;

    if (size <= 100)
        stack->num_chunks = 4;
    else if (size <= 500)
        stack->num_chunks = 10;
    else
        stack->num_chunks = size / 50;

    stack->chunk_size = size / stack->num_chunks;
}

void find_best_elements_in_chunk(t_stack *stack, int chunk_min, int chunk_max, int *first, int *second)
{
    t_node *current = stack->top;
    int i = 0, pos_first = -1, pos_second = -1;
    
    while (current)
    {
        if (current->index_sorted >= chunk_min && current->index_sorted <= chunk_max)
        {
            if (pos_first == -1)
            {
                *first = i;
                pos_first = i;
            }
            else if (pos_second == -1)
            {
                *second = i;
                pos_second = i;
            }
        }
        current = current->next;
        i++;
    }
}

void move_best_to_top(t_stack *stack, int first, int second)
{
    int size = stack->size;
    int moves_first = first;
    int moves_second = (second >= 0) ? (size - second) : size;

    if (moves_first <= moves_second)
        while (moves_first-- > 0) ra(stack);
    else
        while (moves_second-- > 0) rra(stack);
}
int has_chunk_elements(t_stack *stack, int chunk_min, int chunk_max)
{
    t_node *current = stack->top;

    while (current)
    {
        if (current->index_sorted >= chunk_min && current->index_sorted <= chunk_max)
            return 1;
        current = current->next;
    }
    return 0;
}
int find_max_index(t_stack *stack)
{
    t_node *current = stack->top;
    int max_index = current->index_sorted;
    
    while (current)
    {
        if (current->index_sorted > max_index)
            max_index = current->index_sorted;
        current = current->next;
    }
    return max_index;
}
void push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max)
{
    int first, second;
    
    while (has_chunk_elements(stack_a, chunk_min, chunk_max))
    {
        find_best_elements_in_chunk(stack_a, chunk_min, chunk_max, &first, &second);
        move_best_to_top(stack_a, first, second);
        pb(stack_a, stack_b);
    }
}

void move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size > 0)
    {
        move_best_to_top(stack_b, find_max_index(stack_b), -1);
        pa(stack_a, stack_b);
    }
}

void sort_large_stack(t_stack *stack_a , t_stack *stack_b)
{
    define_chunks(stack_a);
    int chunk_min, chunk_max;
    
    // Split stack_a into chunks and push elements to stack_b
    for (int i = 0; i < stack_a->num_chunks; i++)
    {
        chunk_min = i * stack_a->chunk_size;
        chunk_max = (i + 1) * stack_a->chunk_size - 1;
        push_chunk_to_b(stack_a, stack_b, chunk_min, chunk_max);
    }

    // Move elements back from stack_b to stack_a
    move_b_to_a(stack_a, stack_b);
}