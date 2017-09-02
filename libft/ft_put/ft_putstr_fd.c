/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:25:49 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 10:25:50 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (*(unsigned char *)(s + i))
		{
			ft_putchar_fd(*(unsigned char *)(s + i), fd);
			i++;
		}
	}
}
