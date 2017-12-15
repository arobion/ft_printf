/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:10:11 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:40:16 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_in(char *str, char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_count_var(long long var)
{
	int		i;

	i = 0;
	if (var < 0)
		i++;
	if (var == 0)
		return (1);
	while (var != 0)
	{
		var /= 10;
		i++;
	}
	return (i);
}

void		ft_remp_left_preci(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!(tmp = ft_strdup(str)))
		return ;
	i = 0;
	j = 0;
	while (tmp[i] != '\0')
		i++;
	i--;
	while (tmp[i] == ' ' && i >= 0)
	{
		str[j++] = '0';
		i--;
	}
	i = 0;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		str[j++] = tmp[i++];
	free(tmp);
}

void		ft_remp_left_preci2(char *str, t_param param)
{
	int		i;
	char	*tmp;
	int		diff;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '+' || str[0] == '-')
		j++;
	while (ft_isdigit(str[i + j]) == 1)
		i++;
	if (param.precision <= i)
		return ;
	diff = param.precision - i;
	tmp = ft_strdup(str);
	if (j == 1)
		diff++;
	i = j;
	while (i < diff)
		str[i++] = '0';
	while (ft_isdigit(tmp[j]))
		str[i++] = tmp[j++];
	free(tmp);
}
