/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adrlogic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:27:55 by timanish          #+#    #+#             */
/*   Updated: 2025/04/03 21:33:20 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_null(unsigned long long adr, int fd)
{
	if (!adr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	return (0);
}

int	put_adr(unsigned long long ap, int fd)
{
	char	*hex;
	int		count;

	hex = "0x";
	count = 0;
	if (!ap)
		return (p_null(ap, fd));
	write(1, hex, 2);
	count += put_adr_sub(ap, fd);
	return (count);
}

int	put_adr_sub(unsigned long long ap, int fd)
{
	unsigned long long	adr;
	int					count;

	adr = ap;
	count = 2;
	if (!adr)
		return (p_null(adr, fd));
	if (adr >= 16)
		put_adr_sub(adr / 16, 1);
	if (adr < 10)
		ft_putchar_fd(adr + '0', fd);
	else if (adr >= 10)
		ft_putchar_fd("0123456789abcdef"[adr % 16], fd);
	if (!ap)
		return (count + 1);
	while (ap)
	{
		ap /= 16;
		count++;
	}
	return (count);
}
