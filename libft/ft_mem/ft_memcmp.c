/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:38 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:50:41 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
			i++;
		else
		{
			result = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
			return (result);
		}
	}
	return (0);
}
