#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data = {NULL, NULL, NULL, 0};
	if (ac == 1)
		return (0);
	if (joining(ac, av, &data) == 0)
		return (free_data(&data), 0);
	if (!ft_parsing(&data))
		return (free_data(&data), 0);
	init_push_swap(data);
	free_data(&data);
	return (0);
}
