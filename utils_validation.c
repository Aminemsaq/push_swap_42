#include "push_swap.h"

int ft_isvalid(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int is_valid_number(char *number)
{
    int j;
    int sign_t;

    j = 0;
    sign_t = 0;
    if ((number[0] == '+' || number[0] == '-') && !number[1])
        return (printf("Error\n"), 0);
    while (number[j] == '-' || number[j] == '+')
    {
        if (++sign_t > 1)
            return (printf("Error\n"), 0);
        j++;
    }
    while (number[j])
    {
        if (!ft_isvalid(number[j]))
            return (printf("Error\n"), 0);
        j++;
    }
    return (1);
}

int ft_parsing(char **numbers) {
    int i;

    i = 0;
    while (numbers[i]) {
        if (!is_valid_number(numbers[i])) {
            return 0;
        }
        i++;
    }
    int *numbers_int = convert_to_int(numbers);
    if (numbers_int == NULL) {
        return 0;
    }
    i = 0;
    while (numbers_int[i])
    {
        printf("%d\n", numbers_int[i]);
        i++;
    }
    return 1;
}
