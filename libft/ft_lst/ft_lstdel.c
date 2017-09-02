/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:36:07 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/26 12:36:08 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *save;
	t_list *tmp;

	if (!(*alst))
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		save = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = save;
	}
	ft_lstdelone(&tmp, del);
	(*alst) = NULL;
}
