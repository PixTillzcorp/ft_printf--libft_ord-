/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:43:22 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/02 17:43:24 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef union		u_types
{
	int				d;
	char			c;
	long			l;
	short			i;
	void			*ptr;
	char			*s;
	size_t			z;
	wchar_t			wc;
	wint_t			*ws;
	double			dbl;
	long long		ll;
	intmax_t		imt;
	uintmax_t		uimt;
	unsigned int	ud;
	unsigned long	ul;
	unsigned char	uc;
	unsigned short	ui;
}					t_types;

int					ft_helpflag(void);
char				recup_conv(char *flag);
int					ft_islm(const char tag);
char				*add_bin_oct(char *str);
int					ft_isconv(const char tag);
int					ft_isflag(const char format);
int					flag_pre(const char **format);
int					flag_minw(const char **format);
int					pre_wstr(wint_t *str, int pre);
char				*flag_flag(const char **format);
char				*join_flag(char *dest, char *str);
int					ft_printf(const char *format, ...);
void				flag_lm(const char **fmt, char **ret);
char				*add_pre(char *ret, char conv, int pre);
char				*base_swap_bin(va_list *args, char *lm);
int					choice(const char **format, va_list *args);
char				*minw_decimal(char *ret, char *flag, int minw);
int					string(char *str, char *flag, int minw, int pre);
int					no_conv(const char **format, char *flag, int minw);
char				*ptr(va_list *args, char *flag, int minw, int pre);
int					wstring(wint_t *str, char *flag, int minw, int pre);
char				*decimal(va_list *args, char *lm, int pre, char conv);
char				*add_flag(char *ret, char *flag, char conv, int *tab);
char				*add_minw(char *ret, char *flag, char conv, int *tab);
int					convert(va_list *args, char *flag, char *lm, int *tab);
char				*udecimal(va_list *args, char *lm, int pre, char conv);
char				*base_swap_hex(va_list *args, char *lm, int pre, char conv);
char				*base_swap_sci(va_list *args, char *lm, int pre, char conv);
int					flag_conv(const char **fmt, va_list *args,\
					char *flag, int *tab);
int					chrct(va_list *args, char *flag, char *lm,\
					int minw, char conv);
char				*base_swap_oct(va_list *args, char *lm, int pre,\
					char conv, char *flag);
int					check_wsc(va_list args, const char *format);
int					other_conv(va_list *args, char *flag, char *lm, int *tab);

#endif
