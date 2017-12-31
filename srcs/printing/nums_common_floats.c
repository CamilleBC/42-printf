/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common_floats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:23:59 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 12:35:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	print_float_number(long double nb, uint8_t base, t_format format,
			t_buffer *buffer)
{
	uintmax_t	integer;
	long double decimal;

	// We get the integer and decimal part and calculate the decimal len for the precision
	integer = (uintmax_t)nb;
	decimal = nb - integer;
	// If no precision is specified, it is 6
	if (!(format.flags & PRECISION))
		format.precision = 6;
	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	// If the format precision is not 0, we need to subtract 1 more for the '.'
	format.width -= get_nb_len(integer, base);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	// If we need to right justify, and pad with spaces, we do before the prefix
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	// If we need to right justify, and pad with 0, we do that after the prefix
	else if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value("0", format.width, buffer);
	// If precision is 0, we print only the rounded integer part
	if (format.precision == 0)
		print_itoa_base(ft_absl(ft_round(nb)), base, format, buffer);
	// We print the integer part then the point, then the decimal part
	else
	{
		print_itoa_base(ft_absl(integer), base, format, buffer);
		buffered_print(".", 1, buffer);
		print_decimal(ft_absd(decimal), base, format, buffer);
	}
	ft_putstr("\nround: ");
	ft_putnbr(ft_round(nb));
	ft_putchar('\n');
	ft_putstr("\nabsl: ");
	ft_putnbr(ft_absl(ft_round(nb)));
	ft_putchar('\n');
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}