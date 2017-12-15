/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_smaj2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:44:35 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:49:37 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_strdupw(int *str)
{
	int		i;
	int		*ret;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(ret = malloc(sizeof(int) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int		*ft_flags_smaj(int *str, t_param param)
{
	int		i;
	int		*tmp;

	tmp = ft_strdupw(str);
	i = 0;
	while (str[i] != 0)
		i++;
	if (param.precision > 0)
	{
		if ((int)param.width > param.precision)
			i = param.width;
		else
			i = param.precision;
	}
	else if ((int)param.width > i)
		i = param.width;
	if (!(str = malloc(sizeof(int) * i + 1)))
		return (NULL);
	str[i] = 0;
	if (ft_is_in(param.flags, '-'))
		ft_remp_smaj_left(str, tmp, i, param);
	else
		ft_remp_smaj_right(str, tmp, i, param);
	free(tmp);
	return (str);
}

int		ft_verif_byte(wchar_t i, int *tmp)
{
	if (i <= 1114111)
		return (i);
	*tmp = i;
	*tmp = *tmp << 16;
	*tmp = *tmp >> 24;
	return (*tmp);
}

int		*ft_wctoi(wchar_t *str)
{
	int		*ret;
	int		i;
	int		tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_verif_byte(str[i], &tmp)))
			break ;
		i++;
	}
	if (!(ret = malloc(sizeof(int) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_verif_byte(str[i], &tmp)))
			break ;
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
