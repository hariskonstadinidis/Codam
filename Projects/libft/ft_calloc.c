/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:45:34 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/06 12:48:03 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t elements_size)
{
	void	*ptr;

	ptr = malloc(num_elements * elements_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, elements_size * num_elements);
	return (ptr);
}
