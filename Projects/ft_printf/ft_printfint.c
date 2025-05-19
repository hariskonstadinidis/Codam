/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:41:35 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/19 17:20:59 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printfint(int d)
{
	int	sum;

	sum = 0;
	ft_putnbr_fd(d, 1);
	sum = ft_putnumprintf(d);
	return (sum);
}
