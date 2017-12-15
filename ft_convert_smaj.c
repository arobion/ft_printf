/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:41:15 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:49:21 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision_dtc(int *str, t_param *param)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 0 && str[i] <= 127)
			j++;
		else if (str[i] >= 49792 && str[i] <= 57278)
			j += 2;
		else if (str[i] >= 14721152 && str[i] <= 15712191)
			j += 3;
		else if (str[i] < -1114111)
			j += 4;
		if (j > (*param).precision)
		{
			(*param).precision = i;
			return ;
		}
		i++;
	}
	(*param).precision = i;
}

void		ft_precision_noset(int *str, t_param *param)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (ft_unicode(str[i]) >= 0 && ft_unicode(str[i]) <= 127)
			j++;
		else if (ft_unicode(str[i]) >= 49792 && ft_unicode(str[i]) <= 57278)
			j += 2;
		else if (ft_unicode(str[i]) >= 14721152 &&\
				ft_unicode(str[i]) <= 15712191)
			j += 3;
		else if (ft_unicode(str[i]) < -1114111)
			j += 4;
		if (j > (*param).precision)
		{
			(*param).precision = i + 1;
			return ;
		}
		i++;
	}
	(*param).precision = i;
}

void		ft_marre(int *str, t_param *param)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 49792 && str[i] <= 57278)
			(*param).width -= 1;
		else if (str[i] >= 14721152 && str[i] <= 15712191)
			(*param).width -= 2;
		else if (str[i] < -1114111)
			(*param).width -= 3;
		i++;
	}
}

void		ft_convert_smaj2(int *ret, int i, t_param *param)
{
	while (ret[i] != 0)
	{
		if (MB_CUR_MAX == 4)
			ret[i] = ft_unicode(ret[i]);
		i++;
	}
	if ((*param).precision >= 0 && MB_CUR_MAX == 4)
		ft_precision_dtc(ret, param);
	else if ((*param).precision > 1 && MB_CUR_MAX == 1)
		ft_precision_noset(ret, param);
	if ((*param).precision == -1)
		ft_marre(ret, param);
}

int			*ft_convert_smaj(va_list *ap, t_param param)
{
	wchar_t	*str;
	int		*ret;
	int		i;

	i = 0;
	if (param.precision < -2)
		return (0);
	str = va_arg(*ap, wchar_t*);
	if (!(str))
		return (NULL);
	if (!(ret = ft_wctoi(str)))
		return (NULL);
	if (ret == 0)
		return (NULL);
	ft_convert_smaj2(ret, i, &param);
	free(ret);
	ret = ft_flags_smaj(ret, param);
	ft_marre(ret, &param);
	free(ret);
	ret = ft_flags_smaj(ret, param);
	return (ret);
}
