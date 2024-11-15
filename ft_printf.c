/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:33 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/15 17:02:53 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	size_t		count;
	size_t		len;

	len = ft_strlen(format);

	va_start(list, format);
	count = 0;
	i = 0;
	while (i < len)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(list, char *));
			else if (format[i] == 'c')
				count += ft_putchar(va_arg(list, int));
			else if (format[i] == '%')
				count += ft_putchar('%');
			else if (format[i] == 'X' || format[i] == 'x')
				count += ft_puthexa(va_arg(list, unsigned int), format[i] == 'X');
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr_base(va_arg(list, int), "0123456789");
			else if (format[i] == 'u')
				count += ft_putunbr_base(va_arg(list, unsigned int), "0123456789");
			else if (format[i] == 'p')
				count += ft_putptr(va_arg(list, void *));
			i++;
		}
		count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}

/* int main(int argc, char const *argv[])
{
	size_t	size;
	char	*str = " %c";

	size = 0;
	size = ft_printf(str, '0' - 256);
	
	ft_printf("Size : %d\n", size);
	int	*i;

	i = 0;
	
	return 0;
} */

