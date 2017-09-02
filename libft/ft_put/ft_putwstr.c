#include "../libft.h"

int		ft_putwstr(wint_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_putwchar(str[i++]) < 0)
			return (-1);
	}
	return (ft_wstrlen(str));
}
