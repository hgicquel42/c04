/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:38:27 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/04 10:38:29 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_neg(char	*str, int *i)
{
	int	s;

	s = 0;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			s = !s;
		(*i)++;
	}
	return (s);
}

int	ft_satoi(char *str, int s)
{
	int	n;
	int	i;
	int	x;

	n = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		x = str[i] - '0';
		if (s)
			n -= x;
		else
			n += x;
		i++;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	int		s;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	s = ft_neg(str, &i);
	n = ft_satoi(str + i, s);
	return (n);
}

// int	main(void)
// {
// 	printf("42:%d\n", ft_atoi("  \n  42t4457"));
// 	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
// 	printf("0:%d\n", ft_atoi("\0 1337"));
// 	printf("0:%d\n", ft_atoi("-0"));
// 	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
// 	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
// 	printf("-100:%d\n", ft_atoi("-100"));
// 	printf("min:%d\n", ft_atoi("\t---+2147483648"));
// 	printf("max:%d\n", ft_atoi("\v2147483647"));
// }