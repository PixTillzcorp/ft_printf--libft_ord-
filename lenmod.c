#include "ft_printf.h"

void		flag_lm(const char **fmt, char **ret)
{
	char	flag;

	flag = **fmt;
	*ret = ft_chrjoin_free(*ret, flag, 1);
	(*fmt)++;
	if (**fmt == flag && (flag == 'h' || flag == 'l'))
	{
		*ret = ft_chrjoin_free(*ret, flag, 1);
		(*fmt)++;
	}
	while (ft_islm(**fmt))
		(*fmt)++;
}

int			ft_isconv(const char tag)
{
	int		ret;

	ret = 0;
	ret += (tag == 'd' || tag == 'D' ? 1 : 0);
	ret += (tag == 's' || tag == 'S' ? 1 : 0);
	ret += (tag == 'c' || tag == 'C' ? 1 : 0);
	ret += (tag == 'x' || tag == 'X' ? 1 : 0);
	ret += (tag == 'o' || tag == 'O' ? 1 : 0);
	ret += (tag == 'e' || tag == 'E' ? 1 : 0);
	ret += (tag == 'p' || tag == 'i' ? 1 : 0);
	ret += (tag == 'U' || tag == 'u' ? 1 : 0);
	ret += (tag == 'b' || tag == 'H' ? 1 : 0);
	return (ret);
}

int			ft_islm(const char tag)
{
	int		ret;

	ret = 0;
	ret += (tag == 'l' || tag == 'h' ? 1 : 0);
	ret += (tag == 'j' || tag == 'z' ? 1 : 0);
	return (ret);
}

int			convert(va_list *args, char *flag, char *lm, int *tab)
{
	char	*ret;
	char	conv;

	conv = recup_conv(flag);
	if (conv == 'i' || conv == 'd' || conv == 'D')
		ret = decimal(args, lm, tab[1], conv);
	else if (conv == 'c' || conv == 'C')
		return (chrct(args, flag, lm, tab[0], conv));
	else if (conv == 'u' || conv == 'U')
		ret = udecimal(args, lm, tab[1], conv);
	else if (conv == 's' || conv == 'S')
	{
		if (conv == 's' && !lm)
			return (string(va_arg(*args, char *), flag, tab[0], tab[1]));
		return (wstring(va_arg(*args, wint_t *), flag, tab[0], tab[1]));
	}
	else if (conv == 'o' || conv == 'O')
		ret = base_swap_oct(args, lm, tab[1], conv, flag);
	else if (conv == 'x' || conv == 'X')
		ret = base_swap_hex(args, lm, tab[1], conv);
	else if (conv == 'e' || conv == 'E')
		ret = base_swap_sci(args, lm, tab[1], conv);
	else if (conv == 'p')
		ret = ptr(args, flag, tab[0], tab[1]);
	else if (conv == 'b')
		ret = base_swap_bin(args, lm);
	else if (conv == 'H')
		return (ft_helpflag());
	else
		return (0);
	ret = add_flag(ret, flag, conv, tab);
	ft_putstr(ret);
	return ((!ret ? 0 : ft_strlen(ret)));
}

char		recup_conv(char *flag)
{
	char	ret;
	int		i;

	i = 0;
	while (flag[i])
	{
		if (ft_isconv(flag[i]))
		{
			ret = flag[i];
			flag[i] = 0;
			return (ret);
		}
		else
			i++;
	}
	return (0);
}
