/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 20:51:02 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"
#include "arg_print.h"
// DEBUG
#include "print_test.h"

static void	init_format(t_format *format)
{
	format->flag = NULL;
	format->width = 0;
	format->precision = 0;
	format->length = length_unknown;
	format->type = type_unknown;
	format->specifier = '\0';
}


/*
** Returns a pointer to the character after the format, or after what has
** already been printed.
*/

#include <stdio.h>
char	*parse_format(char *str, va_list *app)
{
	char		*ret;
	t_format	format;

	init_format(&format);
	ret = get_specifier(str, &format);
	if (ret != NULL)
		return (ret);
	while (*str != format.specifier)
	{
		seek_flag(&str, &format);
		// printf("flag done");
		seek_width(&str, &format, app);
		// printf("width done");
		seek_precision(&str, &format, app);
		//  printf("preci done");
		seek_length(&str, &format);
		// printf("length done");
	}
	print_test(format);
	return (++str);
}
