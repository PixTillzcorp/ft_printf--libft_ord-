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

	flag = flag_flag(format, 0);
	tab[0] = flag_minw(format);
	if (!(temp = flag_flag(format, 0)))
		free(temp);
	else
		flag = join_flag(flag, temp);
	tab[1] = flag_pre(format);
	if (!(temp = flag_flag(format, 0)))
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
	free(str);
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

int			ft_printf(const char *format, ...)
{
	va_list args;
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strdup(format);
	va_start(args, format);
	if (!ft_ret_free(tmp, check_wsc(args, tmp)))
		return (-1);
	va_end(args);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += choice(&format, &args);
		}
		else
			len += ft_ret_putchar(*(format++));
	}
	va_end(args);
	return (len);
}
