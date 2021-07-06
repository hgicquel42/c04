/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:13:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/05 10:13:51 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_include(char	*str, int l, char c)
{
	int	i;

	i = 0;
	while (i < l && str[i] != c)
		i++;
	if (i == l)
		return (-1);
	return (i);
}

int	ft_neg(char	*str, int *i)
{
	int	s;

	s = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			s = !s;
		(*i)++;
	}
	return (s);
}

int	ft_satoi(char *str, int s, char *base, int l)
{
	int	n;
	int	i;
	int	x;

	n = 0;
	i = 0;
	while (str[i])
	{
		x = ft_include(base, l, str[i]);
		if (x == -1)
			break ;
		n *= l;
		if (s)
			n -= x;
		else
			n += x;
		i++;
	}
	return (n);
}

int	ft_check_base(char *base)
{
	int	i;
	int	l;

	l = 0;
	while (base[l])
	{
		if (base[l] == '-' || base[l] == '+')
			return (0);
		if (base[l] == ' ' || (base[l] >= 9 && base[l] <= 13))
			return (0);
		i = 0;
		while (base[i])
		{
			if ((i != l) && (base[i] == base[l]))
				return (0);
			i++;
		}
		l++;
	}
	return (l);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	s;
	int	l;

	l = ft_check_base(base);
	if (l < 2)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = ft_neg(str, &i);
	n = ft_satoi(str + i, s, base, l);
	return (n);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("42", "0123456789"));
// 	printf("%d\n", ft_atoi_base("101010", "01"));
// 	printf("%d\n", ft_atoi_base("2a", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("52", "01234567"));

// 	printf("%d\n", ft_atoi_base("-42", "0123456789"));
// 	printf("%d\n", ft_atoi_base("-101010", "01"));
// 	printf("%d\n", ft_atoi_base("-2a", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("-52", "01234567"));

// 	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
// 	printf("%d\n", ft_atoi_base("1111111111111111111111111111111", "01"));
// 	printf("%d\n", ft_atoi_base("7fffffff", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("17777777777", "01234567"));

// 	printf("%d\n", ft_atoi_base("2147483648", "0123456789"));
// 	printf("%d\n", ft_atoi_base("10000000000000000000000000000000", "01"));
// 	printf("%d\n", ft_atoi_base("80000000", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("20000000000", "01234567"));

// 	printf("%d\n", ft_atoi_base("0", "0123456789"));
// 	printf("%d\n", ft_atoi_base("0", "01"));
// 	printf("%d\n", ft_atoi_base("0", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("0", "01234567"));

// 	printf("%d\n", ft_atoi_base("-0", "0123456789"));
// 	printf("%d\n", ft_atoi_base("-0", "01"));
// 	printf("%d\n", ft_atoi_base("-0", "0123456789abcdef"));
// 	printf("%d\n", ft_atoi_base("-0", "01234567"));
// }

// int	main(int argc, char **argv)
// {
// 	printf("%d", ft_atoi_base(argv[1], argv[2]));
// 	(void) argc;
// }
