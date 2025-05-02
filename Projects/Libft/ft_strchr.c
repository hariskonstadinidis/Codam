/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:39:39 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/02 15:12:41 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

char	*ft_strchr(char *letter, int a)
{
	while (*letter)
	{
		if (*letter == a)
		{
			return (letter);
		}
		else
		{
			letter++;
		}
	}
	return (letter);
}
