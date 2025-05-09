/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:34:55 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/09 16:26:41 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	count_words(const char *a, char s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (a[i])
	{
		while (a[i] == s)
			i++;
		if (a[i])
		{
			count++;
			while (a[i] && a[i] != s)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word;
	char	**result;

	i = 0;
	word = 0;
	if (s == NULL)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			result[word++] = ft_substr(s, start, i - start);
	}
	result[word] = NULL;
	return (result);
}
