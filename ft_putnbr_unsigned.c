/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:24:52 by hhammiou          #+#    #+#             */
/*   Updated: 2024/11/22 09:22:13 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n < 10)
		ft_putchar(n + 48, len);
	else
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
}
