/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:01:59 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/19 17:19:14 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		sum;
	va_list	args;

	va_start (args, format);
	i = 0;
	sum = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			sum += ft_printfchr(format[i++]);
		if (format[i + 1] == 'c')
		{
			sum += ft_printfchr(va_arg(args, int));
			i += 2;
		}
		else if (format[i + 1] == 's')
		{
			sum += ft_printfstr(va_arg(args, char *));
			i += 2;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			sum += ft_printfint(va_arg(args, int));
			i += 2;
		}
	}
	va_end(args);
	return (sum);
}
