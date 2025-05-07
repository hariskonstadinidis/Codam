/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:44:23 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/05 16:23:46 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(void)
{
    // char a[10] = "test\200";
    // char b[10] = "test\0";
    // printf("%d", ft_strncmp(a,b,8));

    char a[10] = "teste";
    printf("%p", ft_strchr(a, 1024));
}
