/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:45:45 by hariskon          #+#    #+#             */
/*   Updated: 2025/04/23 17:10:11 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *letter, int a)
{
	char	*pointer;
	int		checker;

	checker = 0;
	while (*letter)
	{
		if (*letter == a)
		{
			pointer = letter;
			checker = 1;
			letter++;
		}
		else
		{
			letter++;
		}
	}
	if (checker == 0)
	{
		return (letter);
	}
	else
	{
		return (pointer);
	}
}
