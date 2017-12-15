/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:59:36 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 16:22:46 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoc(int *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(ret = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_modifier_pnt(int *i, int *j, t_param *param)
{
	param->modifier[0] = 'j';
	(*i)++;
	*j = 6;
}

void	ft_modifier_car(int *i, int *j, t_param *param)
{
	param->modifier[0] = 'z';
	(*i)++;
	*j = 4;
}

void	ft_modifier_ter(char *str, int *i, int *j, t_param *param)
{
	if (str[*i + 1] == 'l' && *j < 5)
	{
		param->modifier[0] = 'm';
		*i += 2;
		*j = 5;
	}
	else if (*j < 3)
	{
		param->modifier[0] = 'l';
		(*i)++;
		*j = 3;
	}
}

void	ft_modifier_bis(char *str, int *i, int *j, t_param *param)
{
	if (str[*i + 1] == 'h' && *j < 1)
	{
		param->modifier[0] = 'g';
		*i += 2;
		*j = 1;
	}
	else
	{
		param->modifier[0] = 'h';
		(*i) += 1;
		*j = 2;
	}
}
