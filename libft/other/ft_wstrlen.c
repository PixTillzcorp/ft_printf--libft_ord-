#include "../libft.h"

size_t		ft_wstrlen(wint_t *str)
{
	size_t i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
		count += ft_wcharlen(str[i++]);
	return (count);
}
