/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_remp2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:34:56 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:37:42 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_base_left2(char *str, t_param param,\
		unsigned long long int var)
{
	ft_remp_left_preci2(str, param);
	if (var == 0 && param.precision == 0 && param.width > 0)
	{
		str[0] = '0';
		str[param.width--] = '\0';
		while (param.width > 0)
			str[param.width--] = ' ';
	}
}

void		ft_remp_base_left(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	if (ft_is_in(param.flags, '#') && var != 0)
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
	else
		ft_remp_base_left2(str, param, var);
}

void		ft_remp_base_right(char *str, \
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
	if (ft_is_in(param.flags, '#') && var != 0)
		str[j--] = '0';
	if (ft_is_in(param.flags, '0') && param.precision == -1)
		ft_remp_unsigned_right_birm(j, str);
	else
	{
		while (j >= 0)
			str[j--] = ' ';
	}
	ft_remp_unsigned_right_bis(str, param, var);
}

static void	ft_remp_hex_left2(char *str, t_param param)
{
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else if (param.precision < (int)param.width)
		ft_remp_left_hex(str, param);
}

void		ft_remp_hex_left(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	if (ft_is_in(param.flags, '#') && (var != 0 || param.conv == 'p'))
	{
		str[j++] = '0';
		str[j++] = 'x';
	}
	while (ret[k] != '\0')
	{
		str[k + j] = ret[k];
		k++;
	}
	free(ret);
	j = k + j;
	while (j < i)
		str[j++] = ' ';
	ft_remp_hex_left2(str, param);
}
