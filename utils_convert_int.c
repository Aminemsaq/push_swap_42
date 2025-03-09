#include "push_swap.h"

long *convert_to_int(char **numbers) {
    int count = 0;
    long num;
    int i = 0;

    while (numbers[count]) {
        count++;
    }
    long *numbers_int = malloc(sizeof(long) * count);
    if (numbers_int == NULL) {
        return NULL;
    }
    while (i < count) {
        num =  ft_atoi(numbers[i]);
        if (num > INT_MAX || num < INT_MIN) {
            printf("Error");
            free(numbers_int);
            return NULL;
        }
        numbers_int[i] = num;
        i++;
    }
    return numbers_int;
}