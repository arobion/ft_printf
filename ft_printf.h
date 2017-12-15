/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:06:56 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 15:36:18 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

typedef struct		s_param
{
	char	flags[5];
	char	type_width;
	size_t	width;
	int		precision;
	char	modifier[2];
	char	conv;
}					t_param;

typedef struct		s_norme
{
	int		i;
	int		j;
	int		size;
	int		nb;
	int		m;
}					t_norme;

int					ft_count_unsigned_var(unsigned long int var);
int					ft_iswp(char c);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
int					ft_wputchar(int c);
void				ft_putchar(char c);
char				*ft_unsigned_itoa(unsigned long int n);
char				*ft_long_itoa(long long n);
int					ft_isdigit(int c);
void				ft_strcap(char *s);
char				*ft_strcpy_p(char *dest, const char *src);
int					*ft_ctoi(char *str);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *s);
int					ft_decim(char *str);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
int					ft_count_and_print(int **tab, int k, char *str);
int					ft_print_error2(t_norme *i, char *str, int **tab);
int					ft_printf_error3(t_norme *i, char *str, int **tab);
int					*ft_last_two(t_param param);
int					ft_read_param(char *str, int *i,\
		t_param *param, int *verif);
int					ft_conv(char *str, int *i, t_param *param, int *verif);
int					ft_modifier(char *str, int *i, t_param *param);
int					ft_ismodifier(char c);
void				ft_call_two(int *str, int *tmp);
int					ft_berif_byte(wchar_t i, int *tmp);
int					*ft_wctoi(wchar_t *str);
int					*ft_strdupw(int *str);
int					ft_verif_before_print(int **tab, int k, char *str, int *l);
void				ft_remp_hex_left(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_base_right(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_base_left(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_left_hex(char *str, t_param param);
char				*ft_flags_x(char *str,\
		unsigned long long int var, t_param param);
char				*ft_base_hexa(unsigned long long int nb, t_param param);
int					ft_comp_type(char c, char *tab);
int					ft_comp_type2(char c);
int					ft_count(char *s);
void				ft_countsize(char *s, int *tab);
void				ft_remp_smaj_right_bis(int *str, int *tmp,\
		int i, t_param param);
void				ft_remp_smaj_left_bis(int j, int *str,\
		int *tmp, t_param param);
void				ft_remp_s_right_bis(char *str, char\
		*tmp, int i, t_param param);
void				ft_remp_s_left_bis(int j, char *str,\
		char *tmp, t_param param);
char				*ft_width_ter(char *str, int *i, int *j, int *k);
void				ft_width_bis(char *str, int *j, int *k);
char				*ft_precision_bis(char *str, int *i);
void				ft_modifier_pnt(int *i, int *j, t_param *param);
void				ft_modifier_car(int *i, int *j, t_param *param);
void				ft_modifier_ter(char *str, int *i, int *j, t_param *param);
void				ft_modifier_bis(char *str, int *i, int *j, t_param *param);
char				*ft_itoc(int *str);
int					ft_unicode(int c);
void				ft_remp_s_right(char *str, char *tmp, int i, t_param param);
void				ft_remp_s_left(char *str, char *tmp, int i, t_param param);
void				ft_remp_smaj_right(int *str, int *tmp,\
		int i, t_param param);
void				ft_remp_smaj_left(int *str, int *tmp, int i, t_param param);
void				ft_remp_hex_right(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_unsigned_right_bis(char *str,\
		t_param param, unsigned long long int var);
void				ft_remp_base_right(char *str, int i,\
		t_param param, unsigned long long int var);
int					**ft_strsplit_printf(char *str);
char				*ft_flags_u(unsigned long long int var, t_param param);
int					ft_count_unsigned_var(unsigned long int var);
void				ft_remp_unsigned_left(char *str, \
		unsigned long long int var, int i, t_param param);
void				ft_remp_unsigned_right_birm(int j, char *str);
void				ft_remp_unsigned_right(char *str, \
		unsigned long long int var, int i, t_param param);
int					ft_is_in(char *str, char c);
int					ft_count_var(long long var);
void				ft_remp_left_preci(char *str);
void				ft_remp_left_preci2(char *str, t_param param);
void				ft_remp_left(char *str, \
		long long var, int i, t_param param);
void				ft_remp_right_birm(long long var, \
		int j, char *str, char *param);
void				ft_remp_right(char *str, \
		long long var, int i, t_param param);
int					ft_isflag(char c);
int					ft_width(char *str, int *i, t_param *param);
int					ft_flag(char *str, int *i, t_param *param);
int					ft_precision(char *str, int *i, t_param *param);
int					ft_precision_d(int var, t_param param);
int					*ft_select_conv(va_list *ap, int *str, int *verif);
int					ft_printf(const char *restrict format, ...);
int					*ft_flags_c(int c, t_param param);
int					*ft_flags_smaj(int *str, t_param param);
int					*ft_convert_n(va_list *ap, t_param param);
int					*ft_convert_s(va_list *ap, t_param param);
int					*ft_convert_smaj(va_list *ap, t_param param);
int					*ft_convert_p(va_list *ap, t_param param);
int					*ft_convert_d(va_list *ap, t_param param);
int					*ft_convert_dmaj(va_list *ap, t_param param);
int					*ft_convert_i(va_list *ap, t_param param);
int					*ft_convert_o(va_list *ap, t_param param);
int					*ft_convert_omaj(va_list *ap, t_param param);
int					*ft_convert_u(va_list *ap, t_param param);
int					*ft_convert_umaj(va_list *ap, t_param param);
int					*ft_convert_x(va_list *ap, t_param param);
int					*ft_convert_xmaj(va_list *ap, t_param param);
int					*ft_convert_c(va_list *ap, t_param param);
int					*ft_convert_cmaj(va_list *ap, t_param param);
int					*ft_convert_percent(va_list *ap, t_param param);
int					*ft_convert_ee(va_list *ap, t_param param);
int					*ft_convert_ff(va_list *ap, t_param param);
int					*ft_convert_gg(va_list *ap, t_param param);
int					*ft_convert_aa(va_list *ap, t_param param);

static char			g_base_oct[9] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'\0'
};

static char			g_null[] =
{
	'(',
	'n',
	'u',
	'l',
	'l',
	')',
	'\0'
};

static char			g_tab_char[] =
{
	's',
	'S',
	'p',
	'd',
	'D',
	'i',
	'o',
	'O',
	'u',
	'U',
	'x',
	'X',
	'c',
	'C',
	'%',
	'\0'
};

static char			g_tab_flags[5] =
{
	'#',
	'0',
	'-',
	'+',
	' '
};

static char			g_tab_modifier[4] =
{
	'h',
	'l',
	'j',
	'z',
};

static int			*(*g_tab_ptrf[])(va_list *ap, t_param param) =
{
	ft_convert_s,
	ft_convert_smaj,
	ft_convert_p,
	ft_convert_d,
	ft_convert_dmaj,
	ft_convert_i,
	ft_convert_o,
	ft_convert_omaj,
	ft_convert_u,
	ft_convert_umaj,
	ft_convert_x,
	ft_convert_xmaj,
	ft_convert_c,
	ft_convert_cmaj,
	ft_convert_percent,
};

static char			g_base_hex[17] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',
	'\0'
};

static char			g_ret_two[17] =
{
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

static char			g_ret_three[25] =
{
	'1',
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

static char			g_ret_four[33] =
{
	'1',
	'1',
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

#endif
