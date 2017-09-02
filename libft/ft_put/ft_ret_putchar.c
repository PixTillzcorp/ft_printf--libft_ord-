#include "../libft.h"

int		ft_ret_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
