/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:00 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/02 15:16:25 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	ft_isspace(char a);

int	ft_atoi(char *str)
{
	int		i;
	int		symbol;
	long	result;

	i = 0;
	symbol = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			symbol = -symbol;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = symbol * result;
	return ((int)result);
}

int	ft_isspace(char a)
{
	if (a == ' ' || a == '\f' || a == '\n'
		|| a == '\r' || a == '\t' || a == '\v')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
