#include "../libft.h"

wchar_t		*ft_strwdup(const wchar_t *str)
{
	wchar_t	*cpy;
	int		i;

	i = 0;
	cpy = (wchar_t *)malloc(sizeof(wchar_t) * (ft_strlen((char *)str) + 1));
	if (cpy == NULL)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
