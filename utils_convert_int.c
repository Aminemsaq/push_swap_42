#include "push_swap.h"

int *convert_to_int(char **numbers) {
    int count = 0;
    int i = 0;

    while (numbers[count]) {
        count++;
    }
    int *numbers_int = malloc(sizeof(int) * count);
    if (numbers_int == NULL) {
        return NULL;
    }
    while (i < count) {
        numbers_int[i] = ft_atoi(numbers[i]);
        i++;
    }
    return numbers_int;
}