/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:50:14 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:50:18 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		hex_nbr(const int c, const char conv)
{
	if (conv == 'X')
	{
		if (c >= 65 && c <= 70)
			return (1);
		else if (ft_isdigit(c))
			return (1);
		else
			return (0);
	}
	else if (conv == 'x')
	{
		if (c >= 97 && c <= 102)
			return (1);
		else if (ft_isdigit(c))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

unsigned int	ft_hex_to_dec(const char *str, const char conv)
{
	int nbr;
	int len;
	int i;

	nbr = 0;
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (hex_nbr(str[i], conv))
		{
			nbr += ft_pow(16, len - 1) * (ft_isalpha(str[i]) ?\
			str[i] - 55 : str[i] - 48);
			len--;
			i++;
		}
		else
			return (0);
	}
	return (nbr);
}
