/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:50:05 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/02 16:50:06 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			choice(const char **format, va_list *args)
{
	char	*flag;
	char	*temp;
	int		tab[2];
	int		len;

	flag = flag_flag(format);
	tab[0] = flag_minw(format);
	if (!(temp = flag_flag(format)))
		free(temp);
	else
		flag = join_flag(flag, temp);
	tab[1] = flag_pre(format);
	if (!(temp = flag_flag(format)))
		free(temp);
	else
		flag = join_flag(flag, temp);
	len = flag_conv(format, args, flag, tab);
	return (len);
}

char		*join_flag(char *dest, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(dest, str[i]))
			dest = ft_chrjoin_free(dest, str[i], 1);
		i++;
	}
	return (dest);
}

int			no_conv(const char **format, char *flag, int minw)
{
	int		minus;

	minus = (!ft_strchr(flag, '-') ? 0 : 1);
	if (minw > 0)
	{
		(minus == 1 ? ft_putchar(**format) : 0);
		ft_putxchar((ft_strchr(flag, '0') && !minus ? '0' : ' '), minw - 1);
		(minus == 0 ? ft_putchar(**format) : 0);
		(*format)++;
		return (minw);
	}
	else
		return (0);
}

int			check_wsc(va_list args, const char *format)
{
	char	*lm;
	int		len;

	lm = ft_strdup("");
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			(flag_flag(&format) ? flag_minw(&format) : flag_minw(&format));
			flag_flag(&format);
			if (flag_pre(&format) > 0)
				return (1);
			flag_flag(&format);
			(ft_islm(*format) ? flag_lm(&format, &lm) : 0);
			len = (!ft_strcmp(lm, "l") ? 1 : 0);
			if (((*format == 'c' && len) || (*format == 'C')\
			|| (*format == 's' && len) || (*format == 'S')))
			{
				if ((len = (*format == 'C' || *format == 'c' ? ft_is_wchar(va_arg(args, wint_t)) : ft_is_wstring(va_arg(args, wint_t *)))) == 1 && MB_CUR_MAX == 1)
					return (0);
			}
			else if (*format == '%')
				format++;
			else
				va_arg(args, void *);
		}
		format++;
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list check;
	va_list args;
	int		len;

	len = 0;
	va_start (check, format);
	if (!check_wsc(check, ft_strdup(format)))
		return (-1);
	va_end(check);
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += choice(&format, &args);
		}
		else
		{
			len++;
			ft_putchar(*(format++));
		}
	}
	va_end(args);
	return (len);
}
