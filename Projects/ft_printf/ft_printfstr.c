/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:18:16 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/19 17:19:45 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printfstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_printfchr(str[i]);
		i++;
	}
	return (i);
}
