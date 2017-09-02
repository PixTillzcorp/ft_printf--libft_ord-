/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:48:48 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/07 18:48:50 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putlnbr(long long int n)
{
	long long int mod;
	long long int nbr;

	mod = 0;
	nbr = ABS(n);
	mod = ft_initlmod(nbr, mod);
	if (n < 0)
		ft_putchar('-');
	while (mod != 0)
	{
		ft_putchar('0' + (nbr / mod));
		nbr -= (mod * (nbr / mod));
		mod /= 10;
	}
}
