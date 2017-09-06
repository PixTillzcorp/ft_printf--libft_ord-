/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 01:28:14 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 01:28:15 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*decimal(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char	*ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
	{
		if (conv == 'D')
			ret = ft_litoa((long long)num.l);
		else
			ret = ft_itoa(num.d);
	}
	else if (!ft_strcmp(lm, "l") || conv == 'D')
		ret = ft_litoa((long long)num.l);
	else if (!ft_strcmp(lm, "ll"))
		ret = ft_litoa(num.ll);
	else if (!ft_strcmp(lm, "hh"))
		ret = ft_itoa((int)num.c);
	else if (!ft_strcmp(lm, "h"))
		ret = ft_itoa((int)num.i);
	else if (!ft_strcmp(lm, "j"))
		ret = ft_litoa((long long)num.imt);
	else if (!ft_strcmp(lm, "z"))
		ret = ft_litoa((long long)num.z);
	return ((!ft_strcmp(ret, "0") && !pre ? add_pre(ft_strdup(""), conv, pre) : add_pre(ret, conv, pre)));
}

char		*udecimal(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char	*ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
	{
		if (conv == 'U')
			ret = ft_ulitoa((unsigned long long)num.ul);
		else
			ret = ft_ulitoa((unsigned long long)num.ud);
	}
	else if (!ft_strcmp(lm, "l") || conv == 'U')
		ret = ft_ulitoa((unsigned long long)num.ul);
	else if (!ft_strcmp(lm, "ll"))
		ret = ft_ulitoa((unsigned long long)num.ll);
	else if (!ft_strcmp(lm, "hh"))
		ret = ft_ulitoa((unsigned long long)num.uc);
	else if (!ft_strcmp(lm, "h"))
		ret = ft_ulitoa((unsigned long long)num.ui);
	else if (!ft_strcmp(lm, "j"))
		ret = ft_ulitoa((unsigned long long)num.imt);
	else if (!ft_strcmp(lm, "z"))
		ret = ft_ulitoa((unsigned long long)num.z);
	return ((!ft_strcmp(ret, "0") && !pre ? add_pre(ft_strdup(""), conv, pre) : add_pre(ret, conv, pre)));
}

char		*ptr(va_list *args, char *flag, int minw, int pre)
{
	t_types num;
	char	*ret;
	char	*tmp;

	num.ptr = va_arg(*args, void *);
	ret = ft_ptr_to_hex(num.ptr);
	ret = (!ft_strcmp(ret, "0x0") && !pre ? ft_strdup("0x") : ret);
	if (minw > (int)ft_strlen(ret))
	{
		if (ft_strchr(flag, '0') && !ft_strchr(flag, '-'))
		{
			tmp = ft_strdup(ret + 2);
			free(ret);
			ret = tmp;
		}
		while (minw > (int)ft_strlen(ret))
		{
			if (minw - 2 == (int)ft_strlen(ret) && ft_strchr(flag, '0') && !ft_strchr(flag, '-'))
				ret = ft_strjoin_free("0x", ret, 'r');
			else if (!ft_strchr(flag, '-'))
				ret = ft_strjoin_free((ft_strchr(flag, '0') ? "0" : " "), ret, 'r');
			else
				ret = ft_strjoin_free(ret, " ", 'l');
		}
	}
	return (add_pre(ret, 'p', pre));
}

char		*base_swap_oct(va_list *args, char *lm, int pre, char conv, char *flag)
{
	t_types num;

	num.ll = va_arg(*args, long long);
	if (!lm)
	{
		if (conv == 'O')
			return (ft_ldec_to_base((unsigned long long)num.l, flag, 8, pre));
		return (ft_dec_to_base(num.d, flag, 8, pre));
	}
	else if (!ft_strcmp(lm, "l") || conv == 'O')
		return (ft_ldec_to_base((unsigned long long)num.l, flag, 8, pre));
	else if (!ft_strcmp(lm, "hh"))
		return (ft_dec_to_base((unsigned int)num.uc, flag, 8, pre));
	else if (!ft_strcmp(lm, "h"))
		return (ft_dec_to_base((unsigned int)num.ui, flag, 8, pre));
	else if (!ft_strcmp(lm, "j"))
		return (ft_ldec_to_base((unsigned long long)num.imt, flag, 8, pre));
	else if (!ft_strcmp(lm, "z"))
		return (ft_ldec_to_base((unsigned long long)num.z, flag, 8, pre));
	else if (!ft_strcmp(lm, "ll"))
		return (ft_ldec_to_base(num.ll, flag, 8, pre));
	else
		return (NULL);
}

char		*base_swap_hex(va_list *args, char *lm, int pre, char conv)
{
	t_types num;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ft_dec_to_hex((unsigned int)num.d, conv, pre));
	else if (!ft_strcmp(lm, "l"))
		return (ft_ldec_to_hex((unsigned long long)num.l, conv, pre));
	else if (!ft_strcmp(lm, "hh"))
		return (ft_dec_to_hex((unsigned int)num.uc, conv, pre));
	else if (!ft_strcmp(lm, "h"))
		return (ft_dec_to_hex((unsigned int)num.ui, conv, pre));
	else if (!ft_strcmp(lm, "j"))
		return (ft_ldec_to_hex((unsigned long long)num.imt, conv, pre));
	else if (!ft_strcmp(lm, "z"))
		return (ft_ldec_to_hex((unsigned long long)num.z, conv, pre));
	else if (!ft_strcmp(lm, "ll"))
		return (ft_ldec_to_hex((unsigned long long)num.ll, conv, pre));
	else
		return (NULL);
}
