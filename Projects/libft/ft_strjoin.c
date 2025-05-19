/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:27:19 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/07 12:25:27 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) +1;
	new_string = malloc(total_len);
	if (new_string == NULL)
		return (NULL);
	while (*s1)
	{
		new_string[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		new_string[i] = *s2;
		s2++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
