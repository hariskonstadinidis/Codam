/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:06:58 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/28 15:24:33 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	
	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	len = size - 1;
	while (i < len)
		dest [i] = src[i];
	dest[i] = '\0';
}
