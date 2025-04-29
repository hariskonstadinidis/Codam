/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:21:30 by hkonstan          #+#    #+#             */
/*   Updated: 2025/04/29 17:15:28 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "file.h"

int main()
{
    
    const char src[10] = "Hello";
    char dest[10] = "ll";
    int i;
    
    for (i = -1; i < 7; i++)
    {
        printf("%s %ld\n", dest, strlcat(dest , src, i));
        dest[0] = 'l';
        dest[1] = 'l';
        dest[2] = '\0'; 
    }
    printf("\n");
    for (i = -1; i < 7; i++)
    {
        printf("%s %ld\n", dest, ft_strlcat(dest , src, i));
        dest[0] = 'l';
        dest[1] = 'l';
        dest[2] = '\0'; 
    }
    
    return (0);
}