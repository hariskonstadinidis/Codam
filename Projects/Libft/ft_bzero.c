/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:05:58 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/25 13:10:17 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)array)[i] = 0;
		i++;
	}
}
