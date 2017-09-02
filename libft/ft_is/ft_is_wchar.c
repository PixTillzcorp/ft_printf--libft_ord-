#include "../libft.h"

int		ft_is_wchar(wint_t c)
{
	if (c - 127 > 0 && MB_CUR_MAX == 1)
		return (1);
	return (0);
}
