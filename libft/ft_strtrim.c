/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:00:11 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/10 17:10:29 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (2);
	return (0);
}

int check_for_tab(char const *s1) {
	size_t i = 0;
	
	while (s1[i]) {
		if (ft_check_set(s1[i++]) == 2)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1)
{
	char	*result;
	size_t	size;

	if (!s1)
		return (NULL);
	if (!check_for_tab(s1))
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
