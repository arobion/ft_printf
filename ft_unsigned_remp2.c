/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_remp2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:53:04 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:53:30 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_unsigned_left(char *str, unsigned long long int var, \
		int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_unsigned_itoa(var)))
		return ;
	if (ft_is_in(param.flags, '#') && (param.conv == 'o' || param.conv == 'O'))
		str[j++] = '0';
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
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else if (param.precision < (int)param.width)
		ft_remp_left_preci2(str, param);
}
