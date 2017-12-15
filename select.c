/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:15:01 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 00:11:02 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modif_next(int *verif)
{
	int		i;

	i = 0;
	while (verif[i] != 0)
	{
		verif[i] = verif[i + 1];
		i++;
	}
	verif[i] = 0;
}

int		*ft_last_one(t_param param, int *verif)
{
	int		i;
	int		*ret;

	i = 0;
	if (!(ret = malloc(sizeof(int) * param.width + 1)))
		return (NULL);
	ret[i] = verif[0];
	i++;
	while (i < (int)param.width)
		if (ft_is_in(param.flags, '0'))
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	ret[i] = 0;
	ft_modif_next(verif);
	return (ret);
}

int		*ft_last(t_param param, int *verif)
{
	if (ft_is_in(param.flags, '-'))
		return (ft_last_one(param, verif));
	else
		return (ft_last_two(param));
}

int		ft_norminette_ckoi(int *str, int *i, t_param *param, int *verif)
{
	char	*itc;

	if (!(itc = ft_itoc(str)))
		return (0);
	if (!(ft_read_param(itc, i, param, verif)))
		return (0);
	free(itc);
	return (1);
}

int		*ft_select_conv(va_list *ap, int *str, int *verif)
{
	int		i;
	int		j;
	t_param	param;
	int		*ret;

	i = 1;
	ret = NULL;
	if (!(ft_norminette_ckoi(str, &i, &param, verif)))
		return (NULL);
	j = 0;
	while (g_tab_char[j] != '\0')
	{
		if (g_tab_char[j] == str[i])
		{
			if (!(ret = g_tab_ptrf[j](ap, param)))
				return (NULL);
			return (ret);
		}
		j++;
	}
	free(ret);
	if (param.width > 0)
		return (ft_last(param, verif));
	return (NULL);
}
