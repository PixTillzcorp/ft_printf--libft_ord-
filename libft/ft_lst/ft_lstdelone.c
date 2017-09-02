/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:52:18 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/24 18:52:19 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	(*del)((**alist).content, (**alist).content_size);
	free(*alist);
	*alist = NULL;
}
