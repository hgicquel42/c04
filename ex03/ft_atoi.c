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
