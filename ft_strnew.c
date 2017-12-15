/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:16:03 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:10:52 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*str;

	if (!(str = ft_memalloc(size)))
		return (NULL);
	str[size] = '\0';
	return ((char*)&str[0]);
}
