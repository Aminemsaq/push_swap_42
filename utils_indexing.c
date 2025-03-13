#include "push_swap.h"

int *stack_to_array(t_stack *stack)
{
    int i;

    i = 0;
    if(!stack || stack->size == 0)
        return NULL;
    
    int *arr = malloc(stack->size * sizeof(int));
    if(!arr)
        return NULL;
    t_node *current = stack->top;
    while(i < stack->size)
    {
        arr[i++] = current->value;
        current = current->next;
    }
    return arr;
}

void bubble_sort(int *arr, int size)
{
    int temp;
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < size - 1)
    {   j = 0;
        while(j < size - i - 1)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}


void index_stack(t_stack *stack)
{
    if(!stack || stack->size == 0)
        return ;

    int *sorted_values = stack_to_array(stack);
    if(!sorted_values)
    return ;

    bubble_sort(sorted_values, stack->size);
    int i = 0;
    t_node *current = stack->top;
    while(current){
        i = 0;
        while(i < stack->size){
            if(current->value == sorted_values[i]){
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
    free(sorted_values);
}


void print_stack_with_index(t_stack *stack)
{
    t_node *current = stack->top;
    printf("Stack (value, index): ");
    while (current)
    {
        printf("(%d, %d) ", current->value, current->index);
        current = current->next;
    }
    printf("\n");
}
