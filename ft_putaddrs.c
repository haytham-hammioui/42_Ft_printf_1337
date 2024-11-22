/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:25:01 by hhammiou          #+#    #+#             */
/*   Updated: 2024/11/22 09:33:52 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddrs_hex(unsigned long int n, int *len)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	base = "0123456789abcdef";
	if (n < base_len)
		ft_putchar(base[n], len);
	else
	{
		ft_putaddrs_hex(n / base_len, len);
		ft_putaddrs_hex(n % base_len, len);
	}
}

void	ft_putaddrs(void *addrs, int *len)
{
	unsigned long int	ptr;

	ptr = (unsigned long int)addrs;
	ft_putstr("0x", len);
	ft_putaddrs_hex(ptr, len);
}
