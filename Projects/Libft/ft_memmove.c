/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:16:10 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/25 16:02:56 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "file.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (src > dest && (src - dest < size))
	{
		while (i < size)
		{
			temp[i] = ((unsigned char *)src)[i];
			i++;
		}
		ft_memcpy(dest, temp, size);
	}
	else
	{
		ft_memcpy(dest, src, size);
	}
	return (dest);
}
