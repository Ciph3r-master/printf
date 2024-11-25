/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:39:05 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:39 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int		i;
	int		size;

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

int	ft_putchar(unsigned char c)
{
	return (write(1, &c, 1));
}
