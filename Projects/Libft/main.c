/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:21:30 by hkonstan          #+#    #+#             */
/*   Updated: 2025/04/30 14:35:04 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "file.h"

int main()
{
    
    char src[10] = "12- +-2 -123 44";
    char dest[10] = "ll";
    int i;
    
    printf("%d\n", ft_atoi(src));
    return (0);
}