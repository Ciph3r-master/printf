/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:17 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/25 12:36:12 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getsize(unsigned long nb, size_t baselen)
{
	int			c;

	c = 0;
	while (nb / baselen)
	{
		++c;
		nb /= baselen;
	}
	c++;
	return (c);
}

static void	ft_fillstr(char *s, unsigned long nb, char *base, size_t baselen)
{
	int			size;

	size = ft_getsize(nb, baselen);
	s[size--] = 0;
	while (nb / baselen)
	{
		s[size] = base[nb % baselen];
		nb /= baselen;
		size--;
	}
	s[size] = base[nb % baselen];
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*s;
	int		size;
	size_t	baselen;

	baselen = ft_strlen(base);
	size = ft_getsize(n, baselen);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	ft_fillstr(s, n, base, baselen);
	return (s);
}
