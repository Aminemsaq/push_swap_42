/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:44 by amsaq             #+#    #+#             */
/*   Updated: 2024/11/23 18:14:05 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	src2 = (unsigned char *) src;
	dst2 = (unsigned char *) dst;
	if (src2 == dst2)
		return (src2);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
