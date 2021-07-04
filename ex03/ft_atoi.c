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

int	ft_satoi(char *str, int *i, int s)
{
	int	n;

	n = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		n *= 10;
		if (n < 0)
			n -= str[*i] - '0';
		else
			n += str[*i] - '0';
		if (s)
		{
			n *= -1;
			s = 0;
		}
		(*i)++;
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
	n = ft_satoi(str, &i, s);
	return (n);
}

// int	main(void)
// {
// 	char	str[] = "   --+-2147483647";

// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }