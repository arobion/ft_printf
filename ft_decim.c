/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:04:23 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:11:11 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decim(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		nb = nb * 2 + str[i] - '0';
		i++;
	}
	return (nb);
}
