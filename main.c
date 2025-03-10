#include "push_swap.h"

int main(int ac, char **av)
{
    Data data;
    char **long_numbers;
    if (ac == 2 && av[1][0] == '\0')
    {
        printf("Error: ARGS\n");
        return 1;
    }
    long_numbers = joining(ac, av);
    if (!long_numbers)
        return 0;
    if (!ft_parsing(long_numbers, &data))
        return (free_double(long_numbers), 0);

    init_push_swap(data);
    free_double(long_numbers);
    return 0;
}
