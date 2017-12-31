/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 12:16:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printing.h"

void	print_char(t_format format, va_list *app, t_buffer *buffer)
{
	size_t	width;
	wchar_t	c;

	if (format.flags & UNICODE)
		c = va_arg(*app, wchar_t);
	else
		c = (wchar_t)va_arg(*app, int);
	width = (format.width > 0) ? format.width - ft_wcharlen(c): 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	// if (format.flags & UNICODE)
		buffer_wchar(c, buffer);
	// else
		// buffered_print(c, 1, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
}

void	print_string(t_format format, va_list *app, t_buffer *buffer)
{
	char		*str;
	wchar_t		*wstr;
	intmax_t	len;
	size_t		width;

	if (format.flags & UNICODE)
		wstr = va_arg(*app, wchar_t*);
	else
		str = va_arg(*app, char*);
	len = 0;
	if (format.flags & UNICODE)
		len = (format.flags & PRECISION) ?
		ft_min(format.precision, ft_wstrlen(wstr)) : (intmax_t)ft_wstrlen(wstr);
	else
		len = (format.flags & PRECISION) ?
		ft_min(format.precision, ft_strlen(str)) : (intmax_t)ft_strlen(str);
	width = (format.width - len > 0) ? format.width - len : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value(" ", width, buffer);
	if (format.flags & UNICODE)
		buffer_wstring(wstr, len, buffer);
	else
		buffered_print(str, len, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
}
