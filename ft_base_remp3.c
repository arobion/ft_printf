/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_remp3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:37:12 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 23:37:42 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_left_hex(char *str, t_param param)
{
	int		i;
	char	*tmp;
	int		diff;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '+' || str[0] == '-')
		j++;
	while (str[i + j] != ' ' && str[i + j] != '\0')
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
	while (tmp[j] != ' ')
		str[i++] = tmp[j++];
	free(tmp);
}
