/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:16:48 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 20:16:50 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int		ft_dbl_to_int(double nbr)
{
	int nb;

	nb = (int)(nbr + 1e-9);
	return (nb);
}

char			*ft_dbltoa(double nbr, int pre)
{
	char		*ret;
	int			nb;

	nb = ft_dbl_to_int(nbr);
	nbr -= (double)nb;
	ret = ft_strjoin_free(ft_strdup(""), ft_itoa(nb), 'b');
	ret = ft_chrjoin_free(ret, '.', 1);
	while (nbr > (1 * ft_pow(10, pre * -1)) && (int)ft_strlen(ret) < (pre + 2))
	{
		nbr *= 10;
		nb = ft_dbl_to_int(nbr);
		nbr -= (double)nb;
		ret = ft_strjoin_free(ret, ft_itoa(nb), 'b');
	}
	while ((int)ft_strlen(ret) < (pre + 2))
		ret = ft_chrjoin_free(ret, '0', 1);
	return (ret);
}
