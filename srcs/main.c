/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 22:20:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*arg1 = "Test this.";
	char	arg2 = 'c';
	int		arg3 = 42;
	wchar_t	*arg4 = L"◀▣▶ἀἐἠ";
	wchar_t	arg5 = L'■';

	setlocale(LC_ALL, "en_US.utf8");
	printf   ("Them: \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-10S|\n \
		wchar:   |%12C\n\n", \
			arg1, arg2, arg3, arg4, arg5);
	ft_printf   ("Me  : \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-10S|\n \
		wchar:   |%12C\n\n", \
			arg1, arg2, arg3, arg4, arg5);
	// ft_printf("Mine: \n string: %s\n char: %c\n int: %d\n", arg1, arg2, arg3);
	/* printf("\n\n=======================================\n");
	printf("Testing width detection\n");
	printf("Expression: %%-0.-#+*.10ld width=20\n");
	printf("-------------------------------------------\n");
	ft_printf("Mine2:\n%-0-#+*.10ld\n", 20);
	printf("=======================================\n") */;
}
