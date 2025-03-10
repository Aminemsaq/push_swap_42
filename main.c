#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;
    
    char **long_numbers;
    if (ac == 2 && av[1][0] == '\0')
    {
        printf("Error: ARGS\n");
        return 1;
    }
    long_numbers = joining(ac, av);
    if (!long_numbers)
        return 0;
    if (!ft_parsing(long_numbers)){
        free_double(long_numbers);
        return 0;
    }
    ft_init_stack();
    free_double(long_numbers);
    return 0;
}

