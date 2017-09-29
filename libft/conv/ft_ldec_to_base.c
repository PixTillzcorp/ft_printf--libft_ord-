/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldec_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:35:45 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/15 13:35:48 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char					*ft_ldec_to_base(unsigned long long nbr,\
						char *flag, long long base, int pre)
{
	unsigned long long	rest;
	char				*ret;

	rest = 0;
	if (!nbr)
	{
		if (!pre)
			return (ft_strdup(""));
		return (ft_strdup("0"));
	}
	ret = ft_strdup("");
	while (nbr)
	{
		rest = nbr % base;
		nbr = nbr / base;
		ret = ft_chrjoin_free(ret, (48 + rest), 1);
	}
	ret = ft_retstr_free(ret, ft_strrev(ret));
	while ((int)ft_strlen(ret) + (ft_strchr(flag, '#') ? 1 : 0) < pre)
		ret = ft_strjoin_free("0", ret, 'r');
	return (ret);
}
