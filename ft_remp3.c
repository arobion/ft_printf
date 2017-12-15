/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:40:38 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:43:47 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_left2(char *str, t_param param)
{
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else if (param.precision < (int)param.width)
		ft_remp_left_preci2(str, param);
}

void		ft_remp_left(char *str, long long var, int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_long_itoa(var)))
		return ;
	if (((ft_is_in(param.flags, '+')) && var >= 0))
		str[j++] = '+';
	else if (((ft_is_in(param.flags, ' ')) && var >= 0))
		str[j++] = ' ';
	while (ret[k] != '\0')
	{
		str[k + j] = ret[k];
		k++;
	}
	free(ret);
	j = k + j;
	while (j < i)
		str[j++] = ' ';
	str[j] = '\0';
	ft_remp_left2(str, param);
}
