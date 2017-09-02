#include "ft_printf.h"

int		flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre)
{
	char *lm;
	char *ret;

	lm = ft_strdup("");
	if (ft_islm(**fmt))
		flag_lm(fmt, &lm);
	else
		lm = NULL;
	if (ft_isflag(**fmt))
		flag = join_flag(flag, flag_flag(fmt));
	if (ft_isconv(**fmt))
	{
		flag = ft_chrjoin_free(flag, **fmt, 1);
		(*fmt)++;
		return (convert(args, flag, minw, pre, lm));
	}
	else if (**fmt == '%')
	{
		ret = add_flag(ft_strdup("%"), minw, flag, '%', pre);
		ft_putstr(ret);
		(*fmt)++;
		return (ft_strlen(ret));
	}
	else
		return (no_conv(fmt, flag, minw));
	return (0);
}

int		flag_minw(const char **format)
{
	int ret;

	ret = 0;
	if (!ft_isdigit(**format))
		return (0);
	else
	{
		ret = ft_atoi(*format);
		*format += ft_strlen(ft_itoa(ret));
		return (ret);
	}
}

int		flag_pre(const char **format)
{
	int pre;
	char find;

	find = 0;
	pre = 0;
	if (**format != '.')
		return (-1);
	while (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			if (!find)
			{
				pre = (ft_atoi(*format) <= 0 ? 0 : ft_atoi(*format));
				*format += ft_strlen(ft_itoa(pre));
			}
			else
				*format += ft_strlen(ft_itoa(ft_atoi(*format))); 
		}
		else
			pre = 0;
		find = (!find ? 1 : 1);
	}
	return (pre);
}

int		ft_isflag(const char format)
{
	int ret;

	ret = 0;
	ret += (format == '#' ? 1 : 0);
	ret += (format == '-' ? 1 : 0);
	ret += (format == '+' ? 1 : 0);
	ret += (format == ' ' ? 1 : 0);
	ret += (format == '0' ? 1 : 0);
	return (ret);
}

char 	*flag_flag(const char **format)
{
	char *ret;

	ret = ft_strdup("");
	while (ft_isflag(**format))
	{
		if (ft_strchr(ret, **format))
			(*format)++;
		else
		{
			ret = ft_chrjoin_free(ret, **format, 1);
			(*format)++;
		}
	}
	return (ret);
}
