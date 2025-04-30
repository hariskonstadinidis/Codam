/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:38:58 by hkonstan          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:07 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
#define FILE_H

int ft_isalpha(char a);
int ft_isdigit(char a);
int ft_isalnum(char a);
int ft_isascii(char a);
int ft_isprint(char a);
int ft_strlen(char *array);
int ft_toupper();
int ft_tolower();
char *ft_strchr();
char *ft_strrchr();
int ft_strncmp();
void *ft_memset();
void *ft_memchr();
void *ft_bzero();
void *ft_memcpy();
int ft_memcmp();
void *ft_memmove();
size_t ft_strlcpy();
char *ft_strnstr();
size_t ft_strlcat();
int ft_atoi(char *array);


#endif
