/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:24:35 by amsaq             #+#    #+#             */
/*   Updated: 2024/11/17 20:59:57 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	all;

	all = count * size;
	if (count && all / count != size)
		return (NULL);
	result = (void *) malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (size * count));
	return (result);
}
