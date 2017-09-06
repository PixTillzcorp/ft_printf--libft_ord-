/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldec_to_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:52:13 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:52:14 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char					*ft_ldec_to_bin(unsigned long long nbr)
{
	char				*ret;
	unsigned long long	mod;

	mod = 9223372036854775807;
	ret = ft_strdup("");
	while (mod)
	{
		if (nbr == nbr % mod)
			mod /= 2;
		else
		{
			while (mod)
			{
				if (nbr == nbr % mod)
					ret = ft_chrjoin_free(ret, '0', 1);
				else
				{
					ret = ft_chrjoin_free(ret, '1', 1);
					nbr = nbr % mod;
				}
				mod /= 2;
			}
		}
	}
	return (ret);
}
