#include "../libft.h"

int	ft_is_wstring(wint_t *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_is_wchar(str[i]))
			return (1);
		i++;
	}
	return (0);
}

