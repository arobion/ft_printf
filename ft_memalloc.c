/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:54:13 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:14:09 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	if (size >= 2147483647)
		return (NULL);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1))))
		return (NULL);
	ft_memset(str, 0, size);
	return (&str[0]);
}
