/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:04:52 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/07 11:04:53 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double		ft_pow(int nbr, int power)
{
	double ret;

	ret = (double)(nbr);
	if (!power)
		return (1);
	power = (power > 0 ? power - 1 : power + 1);
	while (power != 0)
	{
		ret = (power > 0 ? (double)(ret * nbr) : (double)(ret / nbr));
		power = (power > 0 ? power - 1 : power + 1);
	}
	return (ret);
}
