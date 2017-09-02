/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:13:41 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/28 12:13:42 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int					ft_initmod(unsigned int nbr, unsigned int mod)
{
	unsigned int	check;
	unsigned int	i;

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
