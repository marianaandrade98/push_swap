#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
			ft_putchar(*s++);
}
