/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:48:18 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 19:48:20 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char				*ft_dec_to_base(unsigned int nbr, char *flag, int base, int pre)
{
	unsigned int	rest;
	char			*ret;

	rest = 0;
	ret = ft_strdup("");
	if (!nbr)
	{
		if (!pre)
			return (NULL);
		return ("0");
	}
	while (nbr)
	{
		rest = nbr % base;
		nbr = nbr / base;
		ret = ft_chrjoin_free(ret, (48 + rest), 1);
	}
	ret = ft_strrev(ret);
	while ((int)ft_strlen(ret) + (ft_strchr(flag, '#') ? 1 : 0) < pre)
		ret = ft_strjoin_free("0", ret, 'r');
	return (ret);
}
