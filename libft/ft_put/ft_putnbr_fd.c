/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:43:52 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:43:53 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int mod;
	unsigned int nbr;

	mod = 0;
	nbr = ABS(n);
	mod = ft_initmod(nbr, mod);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (mod != 0)
	{
		ft_putchar_fd('0' + (nbr / mod), fd);
		nbr -= (mod * (nbr / mod));
		mod /= 10;
	}
}
