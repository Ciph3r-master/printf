/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:33 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:25 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printargs(va_list list, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'X' || c == 'x')
		return (ft_puthexa(va_arg(list, unsigned int), c == 'X'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(list, int), "0123456789"));
	if (c == 'u')
		return (ft_putunbr_base(va_arg(list, unsigned int), "0123456789"));
	if (c == 'p')
		return (ft_putptr(va_arg(list, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	size_t		len;
	size_t		i;
	int			count;

	i = 0;
	len = ft_strlen(format);
	count = 0;
	va_start(list, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			count += ft_printargs(list, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
/* #include "limits.h"
int main(void)
{
	size_t	size;

	size = 0;
	size = ft_printf(" %d\n", 0);
	return 0;
}  */