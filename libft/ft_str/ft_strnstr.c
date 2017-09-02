/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:02:09 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/16 15:08:05 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*ft_strnstr(const char *big, const char *lil, size_t len)
{
	t_dblbbl	index;

	index.i = 0;
	index.j = 0;
	if (ft_strlen(big) < ft_strlen(lil))
		return (NULL);
	if (!lil[index.j])
		return ((char *)big);
	while ((big[index.i] && lil[index.j]) && index.i != len)
	{
		if (big[index.i] == lil[index.j])
		{
			while (big[index.i] == lil[index.j] && index.i != len)
			{
				index.i++;
				index.j++;
				if (!lil[index.j])
					return ((char *)(big + (index.i - index.j)));
			}
			index.i -= index.j;
			index.j = 0;
		}
		index.i++;
	}
	return (NULL);
}
