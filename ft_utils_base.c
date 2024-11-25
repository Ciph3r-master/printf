/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:23:57 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/25 12:33:22 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(int n, char is_upper)
{
	int	size;

	if (is_upper)
		size = ft_putunbr_base(n, "0123456789ABCDEF");
	else
		size = ft_putunbr_base(n, "0123456789abcdef");
	return (size);
}

int	ft_putnbr_base(int n, char *base)
{
	char	*s;
	int		size;

	s = ft_itoa_base(n, base);
	size = ft_putstr(s);
	free(s);
	return (size);
}

int	ft_putunbr_base(unsigned int n, char *base)
{
	char	*s;
	int		size;

	s = ft_ultoa_base(n, base);
	size = ft_putstr(s);
	free(s);
	return (size);
}

int	ft_putptr(void *ptr)
{
	char	*s;
	int		size;

	size = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	s = ft_ultoa_base((size_t)ptr, "0123456789abcdef");
	if (s)
		size = ft_putstr("0x");
	size += ft_putstr(s);
	free(s);
	return (size);
}
