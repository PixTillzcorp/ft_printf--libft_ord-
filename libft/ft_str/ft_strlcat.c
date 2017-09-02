/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:40:33 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:40:34 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t srclen;
	size_t destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		return (size + srclen);
	else if (srclen < (size - destlen))
		ft_strncat(dest, src, size);
	else
		ft_strncat(dest, src, (size - destlen - 1));
	return (srclen + destlen);
}
