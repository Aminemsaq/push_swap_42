#include "push_swap.h"
int ft_isvalid(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}
int ft_parsing(char **numbers)
{
    int i = 0;
    int j = 0;
    int sign_t = 0;
    
    while (numbers[i])
    {
        if ((numbers[i][0] == '+' || numbers[i][0] == '-') && !numbers[i][1])
        {
            printf("Error\n");
            return 0;
        }
        j = 0;
        sign_t = 0;
        while (numbers[i][j] == '-' || numbers[i][j] == '+')
        {
            sign_t++;
            j++;
        }
        if (sign_t > 1)
        {
            printf("Error\n");
            return 0;
        }
        while (numbers[i][j])
        {
            if (!ft_isvalid(numbers[i][j])){
                printf("Error\n");
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    char **numbers;

    if (ac == 2 && av[1][0] == '\0')
    {
        printf("Error: ARGS\n");
        return 1;
    }
    numbers = joining(ac, av);
    if (!numbers)
        return 0;
    if (!ft_parsing(numbers))
        return 0;
    int i = 0;
    while (numbers[i])
    {
        printf("%s\n", numbers[i]);
        i++;
    }
    free_double(numbers);
    return 0;
}
