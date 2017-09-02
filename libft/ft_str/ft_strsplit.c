/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:42:50 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/09 12:42:51 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrword(char const *s, char c)
{
	t_wordi inbr;

	inbr.i = 0;
	inbr.word = 0;
	if (s == NULL)
		return (0);
	while (s[inbr.i])
	{
		while (s[inbr.i] == c && s[inbr.i])
			inbr.i++;
		if (ft_isprint(s[inbr.i]))
		{
			inbr.word++;
			while (s[inbr.i] != c && s[inbr.i])
				inbr.i++;
		}
	}
	return (inbr.word);
}

static int	ft_lenword(char const *s, char c, t_wordi index)
{
	int		len;

	len = 0;
	while (s[index.i] != c && s[index.i])
	{
		len++;
		index.i++;
	}
	return (len);
}

static char	**ft_putintab(char const *s, char **tab, char c, t_wordi *index)
{
	int		j;

	j = 0;
	while (s[index->i] != c && s[index->i])
		tab[index->word][j++] = s[index->i++];
	tab[index->word++][j] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	t_wordi index;
	char	**tab;

	if (!s)
		return (NULL);
	index.i = 0;
	index.word = 0;
	index.lenw = ft_lenword(s, c, index) + 1;
	tab = (char **)malloc(sizeof(char *) * (ft_nbrword(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[index.i])
	{
		if (ft_isprint(s[index.i]) && s[index.i] != c)
		{
			tab[index.word] = (char *)malloc(sizeof(char) * index.lenw);
			tab = ft_putintab(s, tab, c, &index);
			while (ft_isprint(s[index.i]) && s[index.i] && s[index.i] != c)
				index.i++;
		}
		while (s[index.i] == c)
			index.i++;
	}
	tab[index.word] = NULL;
	return (tab);
}
