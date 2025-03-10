/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:00:11 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/09 22:40:20 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c)
{

	if (c == ' ' || c == '\t'){
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1)
{
	char	*result;
	size_t	size;

	if (!s1)
		return (NULL);
	while (*s1 && ft_check_set(*s1) == 1)
		s1++;
	size = ft_strlen(s1);
	while (size != 0 && ft_check_set(s1[size - 1]) == 1)
		size--;
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, size + 1);
	return (result);
}
