/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:42:15 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:42:16 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	while (*(char *)(s + i))
	{
		new[i] = (*f)(*(char *)(s + i));
		i++;
	}
	new[i] = '\0';
	return (new);
}
