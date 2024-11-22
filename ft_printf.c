/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:05:41 by hhammiou          #+#    #+#             */
/*   Updated: 2024/11/19 18:02:21 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(va_list args, const char format, int *len)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (format == '%')
		ft_putchar(format, len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'x' || format == 'X')
		ft_putnbr_base(va_arg(args, int), format, len);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (format == 'p')
		ft_putaddrs(va_arg(args, void *), len);
	else
		ft_putchar(format, len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (write(1, "", 0) < 0)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			check_flags(args, *format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
