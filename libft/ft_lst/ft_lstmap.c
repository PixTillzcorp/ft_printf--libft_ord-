/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:08:31 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/26 16:08:32 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*nelem;
	t_list	**link;
	t_list	**save;

	if (!lst)
		return (NULL);
	save = &nlst;
	link = &nlst;
	nlst = NULL;
	while (lst->next)
	{
		if (nlst)
		{
			nelem = (*f)(ft_lstnew(lst->content, lst->content_size));
			ft_lstappend(link, nelem);
			link = &nlst->next;
		}
		else
			nlst = (*f)(ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	nelem = (*f)(ft_lstnew(lst->content, lst->content_size));
	ft_lstappend(link, nelem);
	return (*save);
}
