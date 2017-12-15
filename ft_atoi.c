/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:17:09 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:26:42 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sign(int *i, const char *str)
{
	if (str[*i] == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (str[*i] == '+')
		*i = *i + 1;
	return (1);
}

static int	ft_over(const char *str)
{
	int			i;
	int			s;
	int			j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && ft_iswp(str[i]) == 1)
		i++;
	s = sign(&i, str);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			break ;
		i++;
		j++;
	}
	if (j >= 19 && s == -1)
		return (0);
	else if (j >= 19 && s == 1)
		return (-1);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		s;

	i = 0;
	res = 0;
	while (str[i] != '\0' && ft_iswp(str[i]) == 1)
		i++;
	s = sign(&i, str);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			return (res * s);
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (ft_over(str) == -1 || ft_over(str) == 0)
		return (ft_over(str));
	return ((res * s));
}
