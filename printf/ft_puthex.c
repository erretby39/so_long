/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:42 by soer-ret          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:48 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long x, char s)
{
	char			*tab;
	unsigned long	c;

	c = x;
	if (x == 0)
		return (write(1, "0", 1));
	if (s == 'x')
		tab = "0123456789abcdef";
	if (s == 'X')
		tab = "0123456789ABCDEF";
	if (c >= 16)
		ft_hex(c / 16, s);
	ft_putchar(tab[c % 16]);
	return (hexlen(x));
}

int	hexlen(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putadd(unsigned long x)
{
	int	n;

	n = 0;
	if (x == 0)
		return (write(1, "(nil)", 5));
	else
	{
		n += write(1, "0x", 2);
		n += hexlen(x);
		ft_hex(x, 'x');
		return (n);
	}
}
