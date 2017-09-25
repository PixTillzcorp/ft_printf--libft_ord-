/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 01:31:44 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 01:32:30 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		goto_conv(va_list args, const char *format)
{
	char		*lm;
	int			len;

	lm = ft_strdup("");
	(flag_flag(&format, 1) ? flag_minw(&format) : flag_minw(&format));
	flag_flag(&format, 1);
	if (flag_pre(&format) > 0)
		return (ft_ret_free(lm, 1));
	flag_flag(&format, 1);
	(ft_islm(*format) ? flag_lm(&format, &lm) : 0);
	len = (!ft_strcmp(lm, "l") ? 1 : 0);
	if (((*format == 'c' && len) || (*format == 'C')\
	|| (*format == 's' && len) || (*format == 'S')))
	{
		if ((len = (*format == 'C' || *format == 'c' ?\
		ft_is_wchar(va_arg(args, wint_t)) : ft_is_wstring(va_arg(args,\
		wint_t *)))) == 1 && MB_CUR_MAX == 1)
			return (ft_ret_free(lm, 0));
	}
	else if (*format == '%')
		format++;
	else
		va_arg(args, void *);
	return (ft_ret_free(lm, 2));
}

int				check_wsc(va_list args, const char *format)
{
	int			ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = goto_conv(args, format);
			if (ret == 1)
				return (1);
			else if (!ret)
				return (0);
		}
		format++;
	}
	return (1);
}

int				other_conv(va_list *args, char *flag, char *lm, int *tab)
{
	char		*ret;
	char		conv;

	conv = recup_conv(flag);
	if (conv == 'o' || conv == 'O')
		ret = base_swap_oct(args, ft_chrjoin_free(flag, conv, 0), lm, tab[1]);
	else if (conv == 'x' || conv == 'X')
		ret = base_swap_hex(args, lm, tab[1], conv);
	else if (conv == 'e' || conv == 'E')
		ret = base_swap_sci(args, lm, tab[1], conv);
	else if (conv == 'b')
		ret = base_swap_bin(args, lm);
	else if (conv == 'p')
		ret = ptr(args, flag, tab[0], tab[1]);
	else if (conv == 'H')
		return (ft_helpflag());
	else
		return (0);
	ret = add_flag(ret, flag, conv, tab);
	ft_putstr(ret);
	if (flag)
		ft_memdel((void **)&flag);
	return ((!ret ? 0 : ft_strlen(ret)));
}
