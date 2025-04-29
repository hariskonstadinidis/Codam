/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:48:53 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:38 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	haystack_i;
	size_t	needle_i;
	size_t	len;

	haystack_i = 0;
	needle_i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack_i < size && haystack[haystack_i] != '\0')
	{
		while (haystack[haystack_i + needle_i] == needle[needle_i]
			&& (haystack_i + needle_i) < size)
		{
			needle_i++;
			if (needle[needle_i] == '\0')
				return ((char *)(&haystack[haystack_i]));
		}
		needle_i = 0;
		haystack_i++;
	}
	return (NULL);
}
