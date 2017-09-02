#include "../libft.h"

char					*ft_ulitoa(unsigned long long nbr)
{
	char				*ret;
	unsigned long long	mod;

	mod = ft_initlmod(nbr, 0);
	ret = ft_strdup("");
	if (nbr == 0)
		return (ft_strdup("0"));
	while (mod != 0)
	{
		ret = ft_chrjoin_free(ret, (nbr / mod) + 48, 1);
		nbr = nbr % mod;
		mod /= 10;
	}
	return (ret);
}