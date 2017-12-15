/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:21 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:17:01 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_ctoi(char *str)
{
	int		*ret;
	int		j;
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != 0)
			i++;
		j = 0;
		if (!(ret = malloc(sizeof(int) * i + 1)))
			return (NULL);
		while (str[j] != '\0')
		{
			ret[j] = str[j];
			j++;
		}
		ret[j] = 0;
		return (ret);
	}
	return (NULL);
}
