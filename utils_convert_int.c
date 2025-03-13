#include "push_swap.h"

int	convert_to_int(t_data *data)
{
	int		count;
	long	num;
	int		i;

	count = 0;
	i = 0;
	while (data->long_split[count])
		count++;
	data->numbers_int = malloc(sizeof(int) * count);
	if (!data->numbers_int)
		return (0);
	while (i < count)
	{
		num = ft_atoi(data->long_split[i], data);
		data->numbers_int[i] = (int)num;
		i++;
	}
	return (1);
}
