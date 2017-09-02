/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:06:15 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:06:16 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((src + i) != dest))
		i++;
	if ((src + i) == dest)
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char *)(dest + i - 1) =\
			*(unsigned char *)(src + i - 1);
			i--;
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
