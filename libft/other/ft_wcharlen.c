#include "../libft.h"

static char	*choose_type(unsigned int len)
{
	if (len > 7)
	{
		if (len > 11)
		{
			if (len > 16)
			{
				if (len > 21)
					return (NULL);
				else
					return ("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
			}
			else
				return ("1110xxxx 10xxxxxx 10xxxxxx");
		}
		else
			return ("110xxxxx 10xxxxxx");
	}
	else
		return ("0xxxxxxx");
}

static char **combine(char *std, char *nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (std[i])
	{
		if (std[i] == 'x')
		{
			if (nbr[j])
				std[i] = nbr[j++];
			else
				std[i] = '0';
		}
		i++;
	}
	std = ft_strrev(std);
	return (ft_strsplit(std, ' '));
}

size_t		ft_wcharlen(wint_t c)
{
	char	*type;
	char	*stock;
	char	**display;
	char	*ret;
	size_t	i;

	type = choose_type(ft_strlen(stock = ft_dec_to_bin((unsigned int)(c))));
	display = combine(ft_strrev(type), ft_strrev(stock));
	free(stock);
	ret = ft_strdup("");
	i = 0;
	while (*display)
	{
		display++;
		i++;
	}
	return (i);
}
