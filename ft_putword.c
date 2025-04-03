/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:20:49 by timanish          #+#    #+#             */
/*   Updated: 2025/04/03 21:30:43 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	count;

	count = 1;
	write(fd, &c, sizeof(char));
	return (count);
}

int	ft_putnbr_fd(long long n, int fd)
{
	long long	nbr;
	int			count;

	count = 0;
	nbr = n;
	if (!nbr)
		count += 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
		count += 1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
	while (n)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		s = "(null)";
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	put_hex(unsigned int ap, char specifier)
{
	unsigned int	hex;
	int				fd;
	int				count;

	fd = 1;
	hex = ap;
	count = 0;
	if (hex >= 16)
		put_hex(hex / 16, specifier);
	if (specifier == 'x')
		ft_putchar_fd("0123456789abcdef"[hex % 16], fd);
	if (specifier == 'X')
		ft_putchar_fd("0123456789ABCDEF"[hex % 16], fd);
	if (!ap)
		count += 1;
	while (ap)
	{
		ap /= 16;
		count++;
	}
	return (count);
}
