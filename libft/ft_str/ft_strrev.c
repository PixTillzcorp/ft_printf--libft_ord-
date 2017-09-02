/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:34:55 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 18:34:58 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strrev(char *str)
{
	char	*ret;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	j = 0;
	i = ft_strlen(str) - 1;
	ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (j < (int)ft_strlen(str))
		ret[j++] = str[i--];
	return (ret);
}
