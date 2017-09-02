#include "ft_printf.h"

char	*add_flag(char *ret, int minw, char *flag, char conv, int pre)
{
	if (!ret)
		ret = ft_strdup("");
	if (ft_strchr(flag, '#'))
	{
		if (!ft_strchr(flag, '0') || ft_strchr(flag, '-'))
		{
			if ((conv == 'o' || conv == 'O') && ft_strcmp(ret, "0"))
				ret = ft_strjoin_free("0", ret, 'r');
			else if ((conv == 'x' || conv == 'X' ) && ft_strcmp(ret, "0") && ft_strcmp(ret, ""))
				ret = ft_strjoin_free((conv == 'x' ? "0x" : "0X"), ret, 'r');
		}
		else if (conv == 'b')
			ret = add_bin_oct(ret);
	}
	if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'e' || conv == 'E')
	{
		if (ft_strchr(flag, '+') && !ft_strchr(ret, '-') && (ft_strchr(flag, '-') || !ft_strchr(flag, '0') || minw < (int)ft_strlen(ret)))
			ret = ft_strjoin_free("+", ret, 'r');
		else if (ft_strchr(flag, ' ') && !ft_strchr(ret, '-') && minw < (int)ft_strlen(ret))
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	return (ret = add_minw(ret, minw, flag, conv, pre));
}

char	*add_minw(char *ret, int minw, char *flag, char conv, int pre)
{
	while ((int)(ft_strlen(ret)) < minw)
	{
		if (ft_strchr(flag, '-'))
			ret = ft_chrjoin_free(ret, ' ', 1);
		else if (ft_strchr(flag, '0') && pre < 0)
		{
			if (ft_strchr(flag, '#') && (int)(ft_strlen(ret) + 2) == minw &&\
				(conv == 'x' || conv == 'X' ) && ft_strcmp(ret, "0"))
				ret = ft_strjoin_free((conv == 'x' ? "0x" : "0X"), ret, 'r');
			else if ((conv == 'd' || conv == 'D'))
				ret = minw_decimal(ret, flag, minw);
			else
				ret = ft_strjoin_free("0", ret, 'r');
		}
		else if (conv == '%' && ft_strchr(flag, '0'))
			ret = ft_strjoin_free("0", ret, 'r');
		else
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	if (conv == 'b' && ft_strcmp(flag, "#"))
		ret = add_bin_oct(ret);
	return (ret);
}

char	*add_bin_oct(char *str)
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strdup("");
	str = ft_strrev(str);
	while (str[i])
	{
		if (i % 8 == 0 && i != 0)
			ret = ft_chrjoin_free(ret, '.', 1);
		else
			ret = ft_chrjoin_free(ret, str[i], 1);
		i++;
	}
	return (ft_strrev(ret));
}

char	*add_pre(char *ret, char conv, int pre)
{
	int neg;

	neg = (ft_strchr(ret, '-') != NULL ? 1 : 0);
	if (pre < 0 || pre < (int)ft_strlen(ret))
		return (ret);
	else if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'u' || conv == 'x' || conv == 'X')
	{
		if (neg)
			*ft_strchr(ret, '-') = '0';
		while ((int)ft_strlen(ret) < pre)
			ret = ft_strjoin_free("0", ret, 'r');
		if (neg)
			ret = ft_strjoin_free("-", ret, 'r');
	}
	else if (conv == 'p')
	{
		ret = ft_strdup(ret + 2); //leaks
		while ((int)ft_strlen(ret) < pre)
			ret = ft_strjoin_free("0", ret, 'r');
		ret = ft_strjoin_free("0x", ret, 'r');
	}
	return (ret);
}

char	*minw_decimal(char *ret, char *flag, int minw)
{
	int neg;
	int esp;

	neg = (ft_strchr(ret, '-') ? 1 : 0);
	esp = (ft_strchr(flag, ' ') && !neg ? 1 : 0);
	if (neg)
		*ft_strchr(ret, '-') = '0';
	while ((int)ft_strlen(ret) < minw - (neg + esp))
		ret = ft_strjoin_free("0", ret, 'r');
	if (neg || esp)
		ret = ft_strjoin_free((neg ? "-" : " "), ret, 'r');
	else if (ft_strchr(flag, '+'))
		*ret = '+';
	return (ret);
}
