/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:21:30 by hkonstan          #+#    #+#             */
/*   Updated: 2025/04/29 16:10:17 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "file.h"

int main()
{
    
    const char src[10] = "Hello";
    const char dest[10] = "ll";
    
    printf("%p\n", strnstr(src , dest, 0));
    printf("%p\n", ft_strnstr(src , dest, 0));

    printf("%s\n", strnstr(src , dest, 4));
    printf("%s\n", ft_strnstr(src , dest, 4));


    printf("%p\n", strnstr(src , dest, 3));
    printf("%p\n", ft_strnstr(src , dest, 3));
    return (0);
}