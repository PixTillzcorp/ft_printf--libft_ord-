/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:48:18 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/04 22:52:02 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char				*ft_dec_to_base(unsigned int nbr, char *flag, int b, int p)
{
	unsigned int	rest;
	char			*ret;

	rest = 0;
	ret = ft_strdup("");
	if (!nbr)
	{
		if (!p)
			return (NULL);
		return ("0");
	}
	while (nbr)
	{
		rest = nbr % b;
		nbr = nbr / b;
		ret = ft_chrjoin_free(ret, (48 + rest), 1);
	}
	ret = ft_strrev(ret);
	while ((int)ft_strlen(ret) + (ft_strchr(flag, '#') ? 1 : 0) < p)
		ret = ft_strjoin_free("0", ret, 'r');
	return (ret);
}
