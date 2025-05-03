/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:16:10 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/03 14:06:03 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	temp[size];

	i = 0;
	while (i < size)
	{
		temp[i] = ((unsigned char *)src)[i];
		i++;
	}
	ft_memcpy(dest, temp, size);
	return (dest);
}
