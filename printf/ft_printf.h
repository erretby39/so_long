/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:04:22 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/06 13:40:49 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_print(char s, va_list args);
int	ft_putadd(unsigned long x);
int	ft_hex(unsigned long x, char s);
int	hexlen(unsigned long nb);
int	nlen(int nb);
int	ft_putnbr(int nb);
int	unslen(unsigned int nb);
int	ft_putuns(unsigned int nb);
int	ft_putchar(int x);
int	ft_putstr(char *s);

#endif