/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:33 by qutruche          #+#    #+#             */
/*   Updated: 2024/12/17 21:04:35 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printargs(va_list list, char c, size_t *i)
{
	*i += 1;
	if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'X' || c == 'x')
		return (ft_puthexa(va_arg(list, unsigned int), c == 'X'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(list, int), "0123456789", 10));
	if (c == 'u')
		return (ft_putunbr_base(va_arg(list, unsigned int), "0123456789", 10));
	if (c == 'p')
		return (ft_putptr(va_arg(list, void *)));
	*i -= 1;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	size_t		i;
	int			count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_printargs(list, format[i + 1], &i);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
