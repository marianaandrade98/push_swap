#include "libft.h"

long long	ft_atoll(char *str)
{
	long long			a;
	long long			b;
	long long			c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if ((str[a] == '-') || (str[a] == '+'))
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = (c * 10) + (b * (str[a] - '0'));
		a++;
	}
	return (c);
}
