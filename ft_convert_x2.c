/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:38:28 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:39:33 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_hexa(unsigned long long int nb, t_param param)
{
	unsigned long long int	tmp;
	int						i;
	char					*str;

	i = 0;
	tmp = nb;
	while (tmp != 0)
	{
		tmp /= 16;
		i++;
	}
	if (nb == 0 && param.precision != 0)
		i = 1;
	if (!(str = ft_strnew(i)))
		return (0);
	if (nb == 0 && param.precision != 0)
		str[--i] = '0';
	while (nb != 0)
	{
		str[--i] = g_base_hex[nb % 16];
		nb /= 16;
	}
	return (str);
}
