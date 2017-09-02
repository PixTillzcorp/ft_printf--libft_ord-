/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:09 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:50:11 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	void *memory;

	if (!(memory = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
