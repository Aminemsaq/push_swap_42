#include "push_swap.h"

int convert_to_int(Data *data)
{
    int count = 0;
    long num;
    int i = 0;

    while (data->long_split[count])
        count++;
    data->numbers_int = malloc(sizeof(int) * count);
    if (!data->numbers_int)
        return 0;
    while (i < count)
    {
        num = ft_atoi(data->long_split[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            printf("Error");
            return 0;
        }
        data->numbers_int[i] = (int)num;
        i++;
    }
    return 1;
}
