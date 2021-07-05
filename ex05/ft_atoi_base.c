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
		x = 0;
		while (base[x] != str[i])
		{
			if (x == l - 1)
				return (0);
			x++;
		}
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
		if (ft_isspace(base[l]))
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
	while (ft_isspace(str[i]))
		i++;
	s = ft_neg(str, &i);
	n = ft_satoi(str + i, s, base, l);
	return (n);
}
