/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:42:36 by soer-ret          #+#    #+#             */
/*   Updated: 2024/12/08 09:44:03 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		count += ft_putuns(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		count += ft_hex(va_arg(args, unsigned int), s);
	else if (s == 'p')
		count += ft_putadd(va_arg(args, unsigned long));
	else if (s == '%')
		count += ft_putchar('%');
	else if (s == 0)
		return (-1);
	else
	{
		count += ft_putchar('%');
		count += write(1, &s, 1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_print(s[i + 1], args);
			if (count == -1)
				break ;
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end (args);
	return (count);
}

// int	main(void)
// {
// 	printf("%d\n", ft_printf("hello %uc i %ul w%uaNT ", 11, 2147483647, NULL));
// 	printf("%d\n", printf("hello %uc i %ul w%uaNT ", 11, 2147483647, NULL));
// 	printf("%d\n", ft_printf("%"));
// 	printf("%d\n", printf("%"));
// }
