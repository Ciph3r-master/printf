/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutruche <qutruche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:05:11 by qutruche          #+#    #+#             */
/*   Updated: 2024/12/17 21:02:07 by qutruche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(unsigned char c);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
int		ft_puthexa(unsigned long n, char is_upper);
int		ft_putnbr_base(int nb, char *base, int baselen);
int		ft_putunbr_base(unsigned long n, char *base, int baselen);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);

#endif