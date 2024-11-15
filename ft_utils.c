/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:39:05 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/15 16:19:33 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_putstr(char *s)
{
	int		i;
	size_t	size;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = -1;
	size = 0;
	while (s[++i])
		size += write(1, &s[i], 1);
	return (size);
}

size_t	ft_putchar(unsigned char c)
{
	size_t	i;

	i = write(1, &c, 1);
	return (i);
}

size_t	ft_puthexa(int n, char is_upper)
{
	size_t	size;

	if (is_upper)
		size = ft_putunbr_base(n, "0123456789ABCDEF");
	else
		size = ft_putunbr_base(n, "0123456789abcdef");
	return (size);
}

size_t	ft_putnbr_base(int n, char *base)
{
	char	*s;
	size_t	size;

	s = ft_itoa_base(n, base);
	size = ft_putstr(s);
	free(s);
	return (size);
}

size_t	ft_putunbr_base(unsigned int n, char *base)
{
	char	*s;
	size_t	size;

	s = ft_uitoa_base(n, base);
	size = ft_putstr(s);
	free(s);
	return (size);
}

size_t	ft_putptr(void *ptr)
{
	char	*s;
	size_t	size;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	s = ft_uitoa_base((size_t)ptr, "0123456789abcdef");
	size = ft_putstr("0x");
	size += ft_putstr(s);
	free(s);
	return (size);
}
