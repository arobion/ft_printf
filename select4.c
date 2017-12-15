/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:29:07 by arobion           #+#    #+#             */
/*   Updated: 2017/12/08 17:20:22 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_bis(char *str, int *i)
{
	int		j;
	char	*ret;

	j = 0;
	(*i)++;
	while (ft_isdigit(str[*i]) == 1)
	{
		(*i)++;
		j++;
	}
	if (!(ret = ft_strnew(j)))
		return (0);
	(*i)--;
	j--;
	while (j >= 0)
		ret[j--] = str[(*i)--];
	return (ret);
}

void	ft_width_bis(char *str, int *j, int *k)
{
	(*k)++;
	(*j)--;
	while (ft_isdigit(str[*j]) == 1)
	{
		(*k)++;
		(*j)--;
	}
}

char	*ft_width_ter(char *str, int *i, int *j, int *k)
{
	int		l;
	char	*ret;

	l = 0;
	(*j)++;
	if (!(ret = ft_strnew(*k)))
		return (NULL);
	*i = *j + *k;
	while (*j != *i)
	{
		ret[l] = str[*j];
		l++;
		(*j)++;
	}
	return (ret);
}
