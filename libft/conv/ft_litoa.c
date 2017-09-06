/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:37:45 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/15 13:37:47 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char					*ft_litoa(long long nbr)
{
	char				*ret;
	unsigned long long	mod;
	unsigned long long	nb;

	if (nbr == 0)
		return (ft_strdup("0"));
	nb = ABS(nbr);
	mod = ft_initlmod(nb, 0);
	ret = ((nbr < 0) ? ft_strdup("-") : ft_strdup(""));
	while (mod != 0)
	{
		ret = ft_chrjoin_free(ret, (nb / mod) + 48, 1);
		nb = nb % mod;
		mod /= 10;
	}
	return (ret);
}
