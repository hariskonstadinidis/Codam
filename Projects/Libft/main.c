/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:21:30 by hkonstan          #+#    #+#             */
/*   Updated: 2025/04/25 16:06:40 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "file.h"

int main()
{
    
    char b[3] = {'b', 'b', '8'};
    char a[3] = {'a', 'f', 'b'};
    

    printf("%p %p\n", a, b);
    // printf("The difference is %s\n", memmove(b, a, 3));
    printf("The difference is %s\n", ft_memmove(b, a, 3));
    return (0);
    
}
