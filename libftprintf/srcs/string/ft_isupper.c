/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:20:51 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/26 23:21:42 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
