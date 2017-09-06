/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:59:46 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/07 18:59:47 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long			ft_initlmod(unsigned long long nbr,\
							unsigned long long mod)
{
	unsigned long long	check;
	unsigned long long	i;

	check = 0;
	i = 1;
	mod = 1;
	while (check != nbr)
	{
		check = nbr % mod;
		while (check != nbr && i <= 9)
		{
			check += i * mod;
			if (check == nbr)
				return (mod);
			else
				check -= i++ * mod;
		}
		i = 1;
		mod *= 10;
	}
	return (mod);
}
