/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:43:11 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:43:12 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strfinish(char const *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (ft_is_white_space(s[i]) && s[i])
		i--;
	return (i + 1);
}

static int	ft_chk_spc(char const *s, int *check)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (ft_is_white_space(s[i]))
	{
		count++;
		i++;
		if (!s[i])
			return (ft_strlen(s));
	}
	if (i == 0)
		*check += 1;
	i = ft_strlen(s) - 1;
	while (ft_is_white_space(s[i]))
	{
		count++;
		i--;
	}
	if (i == ft_strlen(s) - 1)
		*check += 1;
	return (count);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		check;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	check = 0;
	new = (char *)malloc(sizeof(char) *\
		((ft_strlen(s) + 1) - ft_chk_spc(s, &check)));
	if (new == NULL)
		return (NULL);
	if (check == 2)
		return (ft_strdup(s));
	while (ft_is_white_space(s[j]))
		j++;
	while (j < ft_strfinish(s))
		new[i++] = s[j++];
	new[i] = '\0';
	return (new);
}
