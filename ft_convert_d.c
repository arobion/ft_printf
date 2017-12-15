/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:07:08 by arobion           #+#    #+#             */
/*   Updated: 2017/12/14 19:29:21 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_flags_d(long long var, t_param param)
{
	int		i;
	char	*str;

	str = NULL;
	i = ft_count_var(var);
	if (((ft_is_in(param.flags, '+') || ft_is_in(param.flags, ' ')) \
				&& var >= 0))
		i++;
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if (ft_count_var(var) < param.precision && \
			param.precision > (int)param.width && var < 0)
		i++;
	if (var == 0 && param.precision == 0 && param.width == 0)
		return (str);
	if (!(str = malloc(sizeof(int) * i + 1)))
		return (NULL);
	if (ft_is_in(param.flags, '-'))
		ft_remp_left(str, var, i, param);
	else
		ft_remp_right(str, var, i, param);
	return (str);
}

static long long int	var_modifier(long long int var, t_param param)
{
	long long int ret;

	ret = var;
	if (param.modifier[0] == 'h')
		return ((short)ret);
	else if (param.modifier[0] == 'g')
		return ((char)ret);
	else if (param.modifier[0] == 'l')
		return ((long long int)ret);
	else if (param.modifier[0] == 'm')
		return ((long long)ret);
	else if (param.modifier[0] == 'j')
		if (var > 0)
			return (ret);
		else
			return (ret);
	else if (param.modifier[0] == 'z')
		return ((size_t)ret);
	else
		return ((int)ret);
}

int						*ft_convert_d(va_list *ap, t_param param)
{
	long long	var;
	char		*str;
	int			*ret;

	var = va_arg(*ap, long long int);
	var = var_modifier(var, param);
	if (var == 0 && (ft_is_in(param.flags, ' ') || ft_is_in(param.flags, '+'))\
			&& param.precision <= 0 && param.width < 1)
	{
		if (!(str = ft_strnew(2)))
			return (NULL);
		if (ft_is_in(param.flags, '+'))
			str[0] = '+';
		else
			str[0] = ' ';
		if (param.precision == -1)
			str[1] = '0';
	}
	else
		str = ft_flags_d(var, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}

int						*ft_convert_dmaj(va_list *ap, t_param param)
{
	long long int	var;
	char			*str;
	int				*ret;

	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, long long int);
	if (var == 0 && (ft_is_in(param.flags, ' ') || ft_is_in(param.flags, '+'))\
			&& param.precision <= 0 && param.width < 1)
	{
		if (!(str = ft_strnew(2)))
			return (NULL);
		if (ft_is_in(param.flags, '+'))
			str[0] = '+';
		else
			str[0] = ' ';
		if (param.precision == -1)
			str[1] = '0';
	}
	else
		str = ft_flags_d(var, param);
	if (!(ret = ft_ctoi(str)))
		return (0);
	free(str);
	return (ret);
}
