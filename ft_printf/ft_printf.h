/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:26:23 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/17 17:07:48 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putchar(char c, int *len);
void	ft_string(char *s, int *len);
void	ft_hexa_address(size_t p, int *len);
void	ft_putnbr(int n, int *len);
void	ft_unsignedint(unsigned int c, int *len);
void	ft_hexa_putnum(unsigned int p, int *len, char x_or_x);
int		ft_printf(const char *format, ...);

#endif
