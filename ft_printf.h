/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:05:11 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/15 16:15:53 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_putchar(unsigned char c);
size_t	ft_putstr(char *s);
char	*ft_itoa_base(int n, char *base);
size_t	ft_strlen(const char *s);
size_t	ft_puthexa(int n, char is_upper);
size_t	ft_putnbr_base(int n, char *base);
char	*ft_uitoa_base(unsigned long n, char *base);
size_t	ft_putunbr_base(unsigned int n, char *base);
size_t	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif