/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 08:55:36 by timanish          #+#    #+#             */
/*   Updated: 2024/05/27 17:46:22 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_putnbr_fd(long long n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		put_hex(unsigned int ap, char specifier);
int		put_adr(unsigned long long ap, int fd);
int		ap_format(va_list ap, char specifier);
int		space_word(char word);
int		ft_printf(const char *format, ...);

#endif