/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smaj_bis2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:50:10 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:52:15 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_smaj_left_bis(int j, int *str, int *tmp, t_param param)
{
	while (j < param.precision && tmp[j] != 0)
	{
		str[j] = tmp[j];
		if (tmp[0] == '\0')
			str[j] = ' ';
		j++;
	}
	while (j < (int)param.width)
		str[j++] = ' ';
}

void		ft_call_two(int *str, int *tmp)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (tmp[j] != '\0')
	{
		if (tmp[j] >= 49792 && tmp[j] <= 57278)
			i++;
		else if (tmp[j] >= 14721152 && tmp[j] <= 15712191)
			i += 2;
		else if (tmp[j] < -1114111)
			i += 3;
		j++;
	}
	j = 0;
	while (tmp[j] != '\0')
	{
		str[j] = tmp[j + i];
		j++;
	}
}
