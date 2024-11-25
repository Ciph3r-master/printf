/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:17 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/20 16:25:21 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getsize(int nb, size_t baselen)
{
	int			c;
	long int	n;

	c = 0;
	if (nb < 0)
	{
		n = (long int)nb * -1;
		++c;
	}
	else
		n = (long int)nb;
	while (n / baselen)
	{
		++c;
		n /= baselen;
	}
	++c;
	return (c);
}

static void	ft_fillstr(char *s, int nb, char *base, size_t baselen)
{
	long int	n;
	int			size;

	size = ft_getsize(nb, baselen);
	if (nb < 0)
	{
		n = (long int)nb * -1;
		s[0] = '-';
	}
	else
		n = (long int)nb;
	s[size--] = 0;
	while (n / baselen)
	{
		s[size] = base[n % baselen];
		n /= baselen;
		size--;
	}
	s[size] = base[n % baselen];
}

char	*ft_itoa_base(int n, char *base)
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
