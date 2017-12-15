/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:02:29 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:33:28 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_flags_u(unsigned long long int var, \
		t_param param)
{
	int		i;
	char	*str;

	str = NULL;
	i = ft_count_unsigned_var(var);
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if (var == 0 && param.precision == 0 && param.width == 0)
		return (str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (ft_is_in(param.flags, '-'))
		ft_remp_unsigned_left(str, var, i, param);
	else
		ft_remp_unsigned_right(str, var, i, param);
	return (str);
}

unsigned long long int	var_unsigned_modifier(unsigned long long int var, \
		t_param param)
{
	unsigned long long int ret;

	ret = var;
	if (param.modifier[0] == 'h')
		return ((unsigned short)ret);
	else if (param.modifier[0] == 'g')
		return ((unsigned char)ret);
	else if (param.modifier[0] == 'l')
		return ((unsigned long long int)ret);
	else if (param.modifier[0] == 'm')
		return ((unsigned long long int)ret);
	else if (param.modifier[0] == 'j')
		if (var > 0)
			return (ret);
		else
			return (ret);
	else if (param.modifier[0] == 'z')
		return ((size_t)ret);
	else
		return ((unsigned int)ret);
}

int						*ft_convert_u(va_list *ap, t_param param)
{
	unsigned long long int	var;
	int						i;
	char					*str;
	int						*ret;

	i = 0;
	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_unsigned_modifier(var, param);
	str = ft_flags_u(var, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}

unsigned long long int	var_unsigned_maj_modifier(unsigned long long int var, \
		t_param param)
{
	unsigned long long int ret;

	ret = var;
	if (param.modifier[0] == 'h')
		return ((unsigned long int)ret);
	else if (param.modifier[0] == 'g')
		return ((unsigned long)ret);
	else if (param.modifier[0] == 'l')
		return ((unsigned long long int)ret);
	else if (param.modifier[0] == 'm')
		return ((unsigned long long)ret);
	else if (param.modifier[0] == 'j')
		if (var > 0)
			return (ret);
		else
			return (ret);
	else if (param.modifier[0] == 'z')
		return ((size_t)ret);
	else
		return ((unsigned long int)ret);
}

int						*ft_convert_umaj(va_list *ap, t_param param)
{
	char					*str;
	int						*ret;
	int						i;
	unsigned long long int	var;

	i = 0;
	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_unsigned_maj_modifier(var, param);
	str = ft_flags_u(var, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}
