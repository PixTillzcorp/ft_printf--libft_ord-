/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:48:33 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 19:48:35 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_dec_to_hex(unsigned int nbr, char type, int pre)
{
	char	*ret;
	int		rest;
	int		maj_min;

	rest = 0;
	ret = ft_strdup("");
	if (type != 'x' && type != 'X')
		return (NULL);
	else if (!nbr && !pre)
		return (NULL);
	else if (!nbr)
		return ("0");
	maj_min = (type == 'x' ? 97 : 65);
	while (nbr)
	{
		rest = nbr % 16;
		nbr = nbr / 16;
		if (rest >= 10)
			ret = ft_chrjoin_free(ret, (maj_min + (rest % 10)), 1);
		else
			ret = ft_strjoin_free(ret, ft_itoa(rest), 'b');
	}
	while ((int)ft_strlen(ret) < pre)
		ret = ft_strjoin_free(ret, "0", 'l');
	return (ft_retstr_free(ret, ft_strrev(ret)));
}
