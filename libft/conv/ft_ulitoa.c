/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:53:13 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:53:14 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char					*ft_ulitoa(unsigned long long nbr)
{
	char				*ret;
	unsigned long long	mod;

	mod = ft_initlmod(nbr, 0);
	ret = ft_strdup("");
	if (nbr == 0)
		return (ft_strdup("0"));
	while (mod != 0)
	{
		ret = ft_chrjoin_free(ret, (nbr / mod) + 48, 1);
		nbr = nbr % mod;
		mod /= 10;
	}
	return (ret);
}
