#include "push_swap.h"

int *convert_to_int(char **numbers)
{
    int count = 0;
    long num;
    int i = 0;

    while (numbers[count])
        count++;
    int *numbers_int = malloc(sizeof(int) * count);
    if (numbers_int == NULL)
        return NULL;
    while (i < count)
    {
        num = ft_atoi(numbers[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            printf("Error");
            free(numbers_int);
            return NULL;
        }
        numbers_int[i] = (int)num;
        i++;
    }
    return numbers_int;
}
