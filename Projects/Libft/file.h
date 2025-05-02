/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:14:57 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/02 15:16:14 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
#define FILE_H
#include <stddef.h>

int		ft_isalpha(int a);
int		ft_isdigit(int a);
int		ft_isalnum(int a);
int		ft_isascii(int a);
int		ft_isprint(int a);
int		ft_toupper(int a);
int		ft_tolower(int a);
int		ft_strlen(const char *array);

char	*ft_strchr(char *letter, int a);
char	*ft_strnstr(const char *haystack, const char *needle, size_t size);
char	*ft_strrchr(char *letter, int a);
int		ft_strncmp(const char *s1, const char *s2, int size);

void	*ft_memset(void *array, int value, size_t size);
void	*ft_memchr(void *array, int value, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
int		ft_memcmp(const void *array1, const void *array2, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_bzero(void *array, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_atoi(char *array);

void	*ft_calloc(size_t num_elements, size_t elements_size);
char	*ft_strdup(const char *src);

#endif
