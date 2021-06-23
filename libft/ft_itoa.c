/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:11:54 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/23 19:29:14 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strreve(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	str[12];

	i = 0;
	ft_memset(str, 0, 12);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		str[i] = '-';
	ft_strreve(str);
	return (ft_strdup(str));
}
