#include "../libft.h"

char		*ft_strndup(const char *str, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (cpy == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
