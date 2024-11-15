/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:17 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/14 18:59:04 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getsize(unsigned long nb, size_t baselen)
{
	int			c;

	c = 0;
	while (nb != 0)
	{
		++c;
		nb /= baselen;
	}
	return (c);
}

static void	ft_fillstr(char *s, unsigned long nb, char *base, size_t baselen)
{
	int			size;

	size = ft_getsize(nb, baselen);
	s[size--] = 0;
	while (nb != 0)
	{
		s[size] = base[nb % baselen];
		nb /= baselen;
		size--;
	}
}

char	*ft_uitoa_base(unsigned long n, char *base)
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
