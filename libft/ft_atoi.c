/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:16:53 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/10 17:02:30 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	if (c == ' ' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int				i;
	long			result;
	int				sign;

	i = 0;
	sign = 1;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
