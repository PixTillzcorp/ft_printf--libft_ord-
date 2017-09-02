#include "../libft.h"

int		ft_helpflag(void)
{
	ft_putstr("printf([string], [args], [...]);\n");
	ft_putstr("Structure of a conv :");
	ft_putstr("~~> %[- +#0][MinWidth][Pre][LenMod][Conv]\n");
	ft_putstr("MinWidth is an int.\nPre is an int.\nlenMod is an int.\n");
	ft_putstr("Conv can be : [sSidDuUoOxXcCeEHbp%].\n");
	return (186);
}
