/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:40 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/19 17:26:10 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	a;
	int	b;

	// Printchr test//
	a = printf("Hello im %s%d and i want%c", "ss", 100, '5');
	printf("\n");
	b = ft_printf("Hello im %s%d and i want%c", "ss", 100, '5');
	if (a == b)
		printf("\nok\n");
}
