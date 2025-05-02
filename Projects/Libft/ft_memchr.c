/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:22:51 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/02 15:12:09 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "file.h"

void	*ft_memchr(void *array, int value, size_t size)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (unsigned char)value;
	while (i < size)
	{
		if (((unsigned char *)array)[i] == p)
		{
			return (&((unsigned char *)array)[i]);
		}
		i++;
	}
	return (&((unsigned char *)array)[i]);
}
