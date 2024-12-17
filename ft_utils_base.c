/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:23:57 by qutruche          #+#    #+#             */
/*   Updated: 2024/12/17 21:04:11 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char is_upper)
{
	int			size;

	if (is_upper)
		size = ft_putunbr_base(n, "0123456789ABCDEF", 16);
	else
		size = ft_putunbr_base(n, "0123456789abcdef", 16);
	return (size);
}

int	ft_putnbr_base(int nb, char *base, int baselen)
{
	unsigned int	n;
	int				count;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * -1;
		count += 1;
	}
	else
		n = nb;
	if (n >= (unsigned int)baselen)
		count += ft_putnbr_base(n / baselen, base, baselen);
	count += write(1, &base[n % baselen], 1);
	return (count);
}

int	ft_putunbr_base(unsigned long n, char *base, int baselen)
{
	int				count;

	count = 0;
	if (n >= (unsigned long)baselen)
		count += ft_putunbr_base(n / baselen, base, baselen);
	count += write(1, &base[n % baselen], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int		size;

	size = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	size = ft_putstr("0x");
	size += ft_putunbr_base((unsigned long)ptr, "0123456789abcdef", 16);
	return (size);
}
