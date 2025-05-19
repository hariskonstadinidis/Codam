/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:31:00 by hariskon          #+#    #+#             */
/*   Updated: 2025/05/19 17:21:59 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printfchr(char c);
int	ft_printfstr(char *str);
int	ft_printfint(int d);
int	ft_putnumprintf(int n);

#endif