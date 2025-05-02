/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:21:30 by hkonstan          #+#    #+#             */
/*   Updated: 2025/05/02 17:12:17 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "file.h"

int main()
{
    
    char *src  = "Hello";    
    char *dest;
    int i;

    i = 0;
    // while (i < 10)
    // {
    //     printf("%d ", src[i]);
    //     printf("%d \n", dest[i]);
    //     i++;
    // }
    // src = (char *)ft_calloc(10, 1);
    // dest = (int *)ft_calloc(10, 3);
    // i = 0;
    // while (i < 10)
    // {
    //     printf("%d ", src[i]);
    //     printf("%d \n", dest[i]);
    //     i++;
    // }
    
    // dest = ft_strdup(src);
    // printf("%s", dest);
    ft_bzero(dest, 2);
    return (0);
}