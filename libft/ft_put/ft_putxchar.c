#include "../libft.h"

int		ft_putxchar(char c, int x)
{
	int ret;

	if (x > 0)
	{
		ret = x;
		while (x != 0)
		{
			write(1, &c, 1);
			x--;
		}
		return (ret);
	}
	return (-1);
}
