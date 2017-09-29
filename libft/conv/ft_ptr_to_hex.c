/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:17:35 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/07 15:17:37 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ptr_to_hex(void *ptr)
{
	char *ret;
	long rest;
	long nbr;

	rest = 0;
	nbr = (long)(ptr);
	ret = (ptr == NULL ? ft_strdup("0") : ft_strdup(""));
	while (nbr)
	{
		rest = nbr % 16;
		nbr = nbr / 16;
		if (rest >= 10)
			ret = ft_chrjoin_free(ret, (97 + (rest % 10)), 1);
		else
			ret = ft_strjoin_free(ret, ft_itoa(rest), 'b');
	}
	ret = ft_strjoin_free(ret, "x0", 'l');
	return (ft_retstr_free(ret, ft_strrev(ret)));
}
