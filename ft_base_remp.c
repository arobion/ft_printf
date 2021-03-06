/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_remp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:42 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:37:00 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_hex_right_bis(char *str, int j, t_param param,\
		unsigned long long int var)
{
	if (ft_is_in(param.flags, '0') && param.precision == -1)
	{
		ft_remp_unsigned_right_birm(j, str);
		if (ft_is_in(param.flags, '#') && var != 0)
		{
			while (ft_isdigit(str[j]) && j >= 0)
				j--;
			str[++j] = '0';
			str[++j] = 'x';
		}
	}
	else
	{
		while (j >= 0)
			str[j--] = ' ';
		if (ft_is_in(param.flags, '#') && (var != 0 || param.conv == 'p'))
		{
			j = 0;
			while (str[j] == ' ')
				j++;
			str[--j] = 'x';
			str[--j] = '0';
		}
	}
}

void		ft_remp_tamer_preci(char *str, t_param param)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != ' ' && str[i] != '\0')
	{
		i--;
		param.precision--;
	}
	while (param.precision > 0)
	{
		str[i] = '0';
		i--;
		param.precision--;
	}
	while (i >= 0 && param.precision < (int)param.width)
		str[i--] = ' ';
}

static void	ft_remp_tamer2(char *str, int i)
{
	i = 0;
	while (str[i] != '\0' && str[i] != 'x')
		i++;
	if (str[i] != '\0')
		str[i] = '0';
	else
		i--;
	while (str[i] == '0' && i >= 0)
		i--;
	str[i + 2] = 'x';
}

void		ft_remp_tamer(char *str, \
		t_param param, unsigned long long int var)
{
	int		i;

	i = 0;
	if (ft_is_in(param.flags, '#') && (var != 0 || param.conv == 'p'))
		param.precision += 2;
	if (param.precision >= (int)param.width \
			|| param.precision > ft_count_var(var))
		ft_remp_tamer_preci(str, param);
	if (var == 0 && param.precision == 0)
		while (str[i] != '\0')
			str[i++] = ' ';
	if (var == 0 && param.precision == 0 && ft_is_in(param.flags, '#'))
		str[0] = '0';
	i = 0;
	if (ft_is_in(param.flags, '#') && (var != 0 || param.conv == 'p'))
		ft_remp_tamer2(str, i);
}

void		ft_remp_hex_right(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = i;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	while (ret[k] != '\0')
		k++;
	while (k >= 0)
		str[j--] = ret[k--];
	free(ret);
	ft_remp_hex_right_bis(str, j, param, var);
	ft_remp_tamer(str, param, var);
}
