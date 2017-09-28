#include "../libft.h"

char	*ft_retstr_free(void *data, char *ret)
{
	if (data)
		ft_memdel(&data);
	return (ret);
}
