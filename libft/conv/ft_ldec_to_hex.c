/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldec_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:54:51 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:54:53 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char					*ft_ldec_to_hex(unsigned long long nbr,\
						char type, int pre)
{
	char				*ret;
	int					rest;
	unsigned long long	maj_min;

	rest = 0;
	if (type != 'x' && type != 'X')
		return (ft_strdup(""));
	else if (!nbr && !pre)
		return (ft_strdup(""));
	else if (!nbr)
		return (ft_strdup("0"));
	ret = ft_strdup("");
	maj_min = (type == 'x' ? 97 : 65);
	while (nbr)
	{
		rest = nbr % 16;
		nbr = nbr / 16;
		if (rest >= 10)
			ret = ft_chrjoin_free(ret, (maj_min + (rest % 10)), 1);
		else
			ret = ft_strjoin_free(ret, ft_itoa(rest), 'l');
	}
	while ((int)ft_strlen(ret) < pre)
		ret = ft_strjoin_free(ret, "0", 'l');
	return (ft_retstr_free(ret, ft_strrev(ret)));
}
