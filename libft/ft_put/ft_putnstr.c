#include "../libft.h"

void	ft_putnstr(const char *str, int n)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		if (n > 0)
		{
			while (str[i] && i < n)
				ft_putchar(str[i++]);
		}
		else if (n < 0)
			ft_putstr(str);
	}
}
