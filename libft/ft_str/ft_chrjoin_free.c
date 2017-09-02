/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:27:14 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 18:27:20 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_chrjoin_free(char *s, const char c, int flag)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	if (flag == 1)
		free(s);
	return (new);
}
