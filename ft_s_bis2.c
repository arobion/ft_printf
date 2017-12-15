/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_bis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:42:00 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:42:41 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_s_left_bis(int j, char *str, char *tmp, t_param param)
{
	while (j < param.precision && tmp[j] != '\0')
	{
		str[j] = tmp[j];
		if (tmp[0] == '\0')
			str[j] = ' ';
		j++;
	}
	while (j < (int)param.width)
		str[j++] = ' ';
}
