/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:43:26 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:43:27 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_lennbr(unsigned int nbr)
{
	int				i;
	unsigned int	mod;

	i = 1;
	mod = 10;
	while (nbr % mod != nbr)
	{
		mod *= 10;
		i++;
	}
	return (i);
}

static char			*ft_strfromnum(char *str, t_itoa *nb)
{
	str[nb->i] = (nb->nbr / nb->mod) + '0';
	nb->nbr = nb->nbr % nb->mod;
	nb->mod /= 10;
	nb->i++;
	return (str);
}

char				*ft_itoa(int n)
{
	t_itoa			nb;
	char			*str;

	nb.i = 0;
	nb.nbr = ABS(n);
	nb.mod = ft_initmod(nb.nbr, nb.mod);
	nb.negativ = NEG(n);
	str = (char *)malloc(sizeof(char) * (ft_lennbr(nb.nbr) + 1 + nb.negativ));
	if (str == NULL)
		return (0);
	if (n < 0)
		str[nb.i++] = '-';
	while (nb.mod > 0)
		str = ft_strfromnum(str, &nb);
	str[nb.i] = '\0';
	if (str == NULL)
		return (0);
	return (str);
}
