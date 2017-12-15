/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:33:28 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:36:11 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_c_left(int *str, int i)
{
	int		j;

	j = 1;
	while (j < i)
		str[j++] = ' ';
}

static void	ft_remp_c_right(int *str, int i, t_param param)
{
	int		j;
	int		c;

	j = 0;
	c = str[0];
	while (j < i)
	{
		if (ft_is_in(param.flags, '0'))
			str[j++] = '0';
		else
			str[j++] = ' ';
	}
	str[--j] = c;
}

int			*ft_flags_c(int c, t_param param)
{
	int		i;
	int		*str;

	i = 1;
	if (c == 0)
		c = -3;
	if (i < (int)param.width)
		i = (int)param.width;
	if (!(str = malloc(sizeof(int) * i + 1)))
		return (NULL);
	str[i] = 0;
	str[0] = c;
	if (ft_is_in(param.flags, '-'))
		ft_remp_c_left(str, i);
	else
		ft_remp_c_right(str, i, param);
	return (str);
}
