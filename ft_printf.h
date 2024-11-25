/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:05:11 by qutruche          #+#    #+#             */
/*   Updated: 2024/11/20 18:15:49 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(unsigned char c);
int		ft_putstr(char *s);
char	*ft_itoa_base(int n, char *base);
int		ft_strlen(const char *s);
int		ft_puthexa(int n, char is_upper);
int		ft_putnbr_base(int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
int		ft_putunbr_base(unsigned int n, char *base);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);

#endif