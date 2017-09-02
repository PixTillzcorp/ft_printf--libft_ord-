#include "../libft.h"

unsigned int	ft_bin_to_dec(const char *str)
{
	char *temp;
	unsigned int nbr;
	int i;

	nbr = 0;
	i = 0;
	temp = ft_strrev(ft_strdup(str));
	while (temp[i])
	{
		if (temp[i] == '1')
			nbr += ft_pow(2, i);
		i++;
	}
	free(temp);
	return (nbr);
}