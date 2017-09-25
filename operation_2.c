/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 01:28:19 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 01:28:21 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*base_swap_bin(va_list *args, char *lm)
{
	t_types num;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ft_dec_to_bin(num.ud));
	else if (ft_strcmp(lm, "l"))
		return (ft_ldec_to_bin((long long)num.l));
	else if (ft_strcmp(lm, "ll"))
		return (ft_ldec_to_bin(num.ll));
	else
		return (NULL);
}

char		*base_swap_sci(va_list *args, char *lm, int pre, char conv)
{
	t_types num;

	num.dbl = va_arg(*args, double);
	if (!lm)
		return (ft_dec_to_sci(num.dbl, conv, pre));
	else
		return (NULL);
}

int			chrct(va_list *args, char *flag, char *lm, int minw)
{
	t_types num;
	int		len;
	char	conv;

	len = 0;
	conv = recup_conv(flag);
	num.ll = va_arg(*args, long long);
	if (!ft_strchr(flag, '-'))
		ft_putxchar(O_S, minw - 1);
	if (conv == 'C')
		len += ft_putwchar(num.wc);
	else if (conv == 'c' && !lm)
	{
		ft_putchar(num.c);
		len++;
	}
	else if (!ft_strcmp(lm, "l"))
		len += ft_putwchar(num.wc);
	if (ft_strchr(flag, '-'))
		ft_putxchar(' ', minw - 1);
	return ((minw > 0 ? (minw + (len - 1)) : len));
}

int			string(char *str, char *flag, int minw, int pre)
{
	int		len;
	int		i;
	int		strl;

	i = 0;
	len = 0;
	if (str == NULL)
		str = ft_strdup("(null)");
	strl = ft_strlen(str);
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && !ft_strchr(flag, '-'))
	{
		len += ft_putxchar(O_S, minw - (pre >= 0 && pre < strl ? pre : strl));
	}
	while ((pre >= 0 && pre < strl ? i != pre : str[i]))
	{
		ft_putchar(str[i++]);
		len += 1;
	}
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && ft_strchr(flag, '-'))
		len += ft_putxchar(' ', minw - (pre >= 0 && pre < strl ? pre : strl));
	return (len);
}

int			wstring(wint_t *str, char *flag, int minw, int pre)
{
	int		len;
	int		i;
	int		count;
	int		strl;

	i = 0;
	len = 0;
	count = 0;
	if (!str)
		return (string(NULL, flag, minw, pre));
	strl = ft_wstrlen(str);
	pre = pre_wstr(str, pre);
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && !ft_strchr(flag, '-'))
		len += ft_putxchar(O_S, minw - (pre >= 0 && pre < strl ? pre : strl));
	while ((pre >= 0 && pre < strl ? count < pre : str[i]))
	{
		count += (ft_is_wstring(str) && MB_CUR_MAX == 1 ?\
		ft_ret_putchar(str[i++]) : ft_putwchar(str[i++]));
		if ((int)ft_wcharlen(str[i]) > pre - count && pre >= 0)
			break ;
	}
	len += count;
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && ft_strchr(flag, '-'))
		len += ft_putxchar(' ', minw - (pre >= 0 && pre < strl ? pre : strl));
	return (len);
}
