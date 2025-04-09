/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:14:32 by soer-ret          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:01 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nlen(int nb)
{
	int	n;
	int	i;

	n = nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return (nlen(nb));
}

int	unslen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putuns(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	if (n > 9)
	{
		ft_putuns(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	return (unslen(nb));
}
