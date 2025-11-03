/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:42:10 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/07 16:22:19 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*substring;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_len = ft_strlen(s);
	if (new_len <= (size_t)start)
		len = 0;
	else if (new_len - start < len)
		len = new_len - start;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}
