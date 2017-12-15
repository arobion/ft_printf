/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:54:27 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:56:46 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ismodifier(char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_tab_modifier[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_modifier(char *str, int *i, t_param *param)
{
	int		j;

	j = 0;
	param->modifier[0] = '0';
	while (str[*i] != '\0')
	{
		if (ft_ismodifier(str[*i]))
		{
			if (str[*i] == 'h' && j < 2)
				ft_modifier_bis(str, i, &j, param);
			else if (str[*i] == 'l' && j < 5)
				ft_modifier_ter(str, i, &j, param);
			else if (str[*i] == 'z' && j < 4)
				ft_modifier_car(i, &j, param);
			else if (str[*i] == 'j' && j < 6)
				ft_modifier_pnt(i, &j, param);
			else if (str[*i] != '\0')
				(*i)++;
		}
		else if (str[*i] != '\0')
			(*i)++;
	}
	return (1);
}

int		ft_conv(char *str, int *i, t_param *param, int *verif)
{
	int		j;

	j = 0;
	while (str[*i] != '\0')
		(*i)++;
	(*i)--;
	if (str[*i] == '%' && *i == 0)
	{
		(*i)++;
		return (1);
	}
	while (g_tab_char[j] != '\0')
	{
		if (str[*i] == g_tab_char[j])
		{
			param->conv = str[*i];
			return (1);
		}
		j++;
	}
	if (verif == NULL)
		return (0);
	else
		return (1);
}

int		ft_read_param(char *str, int *i, t_param *param, int *verif)
{
	int		j;

	j = 0;
	while (j < 5)
		param->flags[j++] = 'R';
	param->precision = -1;
	param->width = 0;
	*i = 1;
	if (!(ft_flag(str, i, param)))
		return (0);
	*i = 1;
	if (!(ft_width(str, i, param)))
		return (0);
	*i = 1;
	if (!(ft_precision(str, i, param)))
		return (0);
	*i = 1;
	if (!(ft_modifier(str, i, param)))
		return (0);
	*i = 1;
	if (!(ft_conv(str, i, param, verif)))
		return (0);
	return (1);
}

int		*ft_last_two(t_param param)
{
	int		i;
	int		*ret;

	i = 0;
	if (!(ret = malloc(sizeof(int) * param.width)))
		return (NULL);
	param.width--;
	while (i < (int)param.width)
		if (ft_is_in(param.flags, '0'))
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}
