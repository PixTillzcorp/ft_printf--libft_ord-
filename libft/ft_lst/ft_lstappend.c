/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:30:16 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/26 16:30:17 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		while ((**alst).next)
			*alst = (**alst).next;
		(**alst).next = new;
	}
}
