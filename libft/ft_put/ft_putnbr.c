/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:43:46 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:43:47 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(int n)
{
	unsigned int mod;
	unsigned int nbr;

	mod = 0;
	nbr = ABS(n);
	mod = ft_initmod(nbr, mod);
	if (n < 0)
		ft_putchar('-');
	while (mod != 0)
	{
		ft_putchar('0' + (nbr / mod));
		nbr -= (mod * (nbr / mod));
		mod /= 10;
	}
}
