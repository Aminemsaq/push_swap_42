#include "push_swap.h"

char **joining(int ac, char **av)
{
    int i = 1;
    char *long_number = NULL;
    char **numbers = NULL   ;

    while (i < ac)
    {
        if (help_join(av[i]) == 0)
        {
            printf("Erroor");
            return (free(long_number), NULL);
        }
        char *temp = ft_strjoin(long_number, av[i]);
        free(long_number);
        long_number = temp;
        if (i < ac - 1)
        {
            temp = ft_strjoin(long_number, " ");
            free(long_number);
            long_number = temp;
        }
        i++;
    }
    numbers = ft_split(long_number, ' ');
    return (free(long_number), numbers);
}

int help_join(char *number)
{
    char *str = ft_strtrim(number);
    if (!str)
        return (0);
    if (str[0] == '\0')
    {
        free(str);
        return 0;
    }
    free(str);
    return 1;
}

void free_double(char **tbl)
{
    int i = 0;
    while (tbl[i])
    {
        free(tbl[i]);
        i++;
    }
    free(tbl);
}
