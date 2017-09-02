/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:00:36 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/16 15:04:25 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*(char *)(s + i))
	{
		if (*(char *)(s + i) == c)
			return ((char *)(s + i));
		else if (c == '\0')
			return ((char *)(s + ft_strlen(s)));
		else
			i++;
	}
	return (NULL);
}
