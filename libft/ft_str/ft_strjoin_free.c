/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:25:47 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 18:25:49 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*ft_strjoin_free(char *s1, char *s2, char flag)
{
	char		*out;

	out = ft_strjoin(s1, s2);
	if (flag == 'l' || flag == 'b')
		free(s1);
	if (flag == 'r' || flag == 'b')
		free(s2);
	return (out);
}
