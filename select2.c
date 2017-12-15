/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:27:18 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:21:16 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isflag(char c)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (g_tab_flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_precision(char *str, int *i, t_param *param)
{
	int		j;
	char	*ret;

	j = 0;
	while (str[*i] != '\0')
		(*i)++;
	while (*i >= 0)
	{
		if (str[*i] == '.')
		{
			if (!(ret = ft_precision_bis(str, i)))
				return (0);
			param->precision = ft_atoi(ret);
			free(ret);
			return (1);
		}
		(*i)--;
	}
	return (1);
}

int			ft_flag(char *str, int *i, t_param *param)
{
	int		j;

	j = 0;
	while (str[*i] != '\0')
	{
		if (j > 4)
			return (1);
		if (ft_is_in(g_tab_flags, str[*i]) == 1 &&\
				ft_is_in(param->flags, str[*i]) == 0)
		{
			param->flags[j] = str[*i];
			if (str[*i] == '0' && (ft_isdigit(str[*i - 1]) \
					|| str[*i - 1] == '.'))
				param->flags[j] = 'R';
			else
				j++;
		}
		(*i)++;
	}
	return (1);
}

static void	norminette_useless(int *k, int *j)
{
	*k = 0;
	*j = 1;
}

int			ft_width(char *str, int *i, t_param *param)
{
	char	*ret;
	int		j;
	int		k;

	norminette_useless(&k, &j);
	while (str[j] != '\0')
		j++;
	while (j >= 1)
	{
		while (ft_isdigit(str[j]) == 0 && j >= 1)
			j--;
		if (ft_isdigit(str[j]) == 1)
		{
			ft_width_bis(str, &j, &k);
			if (str[j] != '.')
			{
				if (!(ret = ft_width_ter(str, i, &j, &k)))
					return (0);
				param->width = ft_atoi(ret);
				free(ret);
				return (1);
			}
		}
	}
	return (1);
}
