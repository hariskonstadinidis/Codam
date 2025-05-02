/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:16:49 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/02 15:12:32 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "file.h"

void	*ft_memset(void *array, int value, size_t size)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (unsigned char)value;
	while (i < size)
	{
		((unsigned char *)array)[i] = p;
		i++;
	}
}
