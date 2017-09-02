/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:45:09 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/16 14:55:38 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_spaces(char c)
{
	if (c == '\t' || c == '\v' || c == '\r'\
		|| c == '\f' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_isdig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_numfromstr(const char *str, int nb, int i)
{
	if (nb == 0)
		nb = str[i] - '0';
	else
		nb = (nb * 10) + str[i] - '0';
	return (nb);
}

static int	ft_chkplmn(const char *str, int *changed, int signe, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		*changed = 1;
	}
	return (signe);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		signe;
	int		changed;

	i = 0;
	nb = 0;
	signe = 1;
	changed = 0;
	while ((ft_is_spaces(str[i]) || str[i] == '-' ||\
		str[i] == '+') && changed == 0)
		signe = ft_chkplmn(str, &changed, signe, i++);
	while (ft_isdig(str[i]))
		nb = ft_numfromstr(str, nb, i++);
	return (nb * signe);
}
