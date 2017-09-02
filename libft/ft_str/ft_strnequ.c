/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:41:36 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:41:37 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
