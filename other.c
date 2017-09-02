#include "ft_printf.h"

int		pre_wstr(wint_t *str, int pre)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (!pre)
		return (0);
	if ((int)ft_wstrlen(str) < pre)
		return (-1);
	while (pre > count && str[i])
	{
		if ((int)(count + ft_wcharlen(str[i])) > pre)
			return (count);
		count += ft_wcharlen(str[i++]);
		if ((int)(count + ft_wcharlen(str[i])) > pre)
			return (count);
	}
	return (-1);
}

int		ft_helpflag(void)
{
	ft_putstr("printf([string], [args], [...]);\n");
	ft_putstr("Structure of a conv :");
	ft_putstr("~~> %[- +#0][MinWidth][Pre][LenMod][Conv]\n");
	ft_putstr("MinWidth is an int.\nPre is an int.\nlenMod is an int.\n");
	ft_putstr("Conv can be : [sSidDuUoOxXcCeEHbp%].\n");
	return (186);
}
