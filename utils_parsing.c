#include "push_swap.h"

int ft_isvalid(char c)
{
    if (((c >= '0' && c <= '9') || c == '\t'))
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
        return (printf("Errorn\n"), 0);
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

int ft_parsing(char **numbers, Data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (numbers[i])
    {
        if (!is_valid_number(numbers[i]))
            return 0;
        i++;
    }
    int *numbers_int = convert_to_int(numbers);
    if (numbers_int == NULL)
        return 0;
    if (!check_dupl(numbers_int, i))
    {
        printf("Error");
        return (free(numbers_int), 0);
    }
    if (check_sorted(numbers_int, i))
        return (free(numbers_int), 0);
    data->numbers_int = numbers_int;
    data->size = i;
    return 1;
}

int check_dupl(int *numbers_int, int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (numbers_int[i] == numbers_int[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int check_sorted(int *numbers_int, int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (numbers_int[i] > numbers_int[j])
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}
