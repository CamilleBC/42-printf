/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:00:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 10:19:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void print_fraction(long double nb, uint8_t base, t_format format,
						  t_buffer *buffer)
{
	while (format.precision > 0)
	{
		nb *= base;
		if (nb == 0)
			buffered_print("0", 1, buffer);
		format.precision--;
	}
	if (nb != 0)
		print_itoa_base(ft_round(nb), base, format, buffer);
}

void print_exponent(int64_t exponent, uint8_t base, t_format format,
						   t_buffer *buffer)
{
	if (base == 16)
	{
		if (format.flags & UPPERCASE)
			buffered_print("P", 1, buffer);
		else
			buffered_print("p", 1, buffer);
	}
	else
	{
		if (format.flags & UPPERCASE)
			buffered_print("E", 1, buffer);
		else
			buffered_print("e", 1, buffer);
	}
	if (exponent >= 0)
		buffered_print("+", 1, buffer);
	else
		buffered_print("-", 1, buffer);
	if (((exponent < 9) && (exponent > -9)) && (base == 10))
		buffered_print("0", 1, buffer);
	print_itoa_base(ft_absl(exponent), 10, format, buffer);
}
