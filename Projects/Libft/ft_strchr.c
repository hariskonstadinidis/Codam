/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:39:39 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/23 16:48:55 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
