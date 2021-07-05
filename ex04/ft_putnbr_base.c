/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:49:24 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/04 12:49:25 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_lbase(int nb, char *base, int l)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = base[-(nb % l)];
	}
	else
		c = base[nb % l];
	if (nb < -l)
		ft_putnbr_lbase(-(nb / l), base, l);
	if (nb > l)
		ft_putnbr_lbase(nb / l, base, l);
	write(1, &c, 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		l;
	int		i;

	l = 0;
	while (base[l])
	{
		if (base[l] == '-' || base[l] == '+')
			return ;
		if (ft_isspace(base[l]))
			return ;
		i = 0;
		while (base[i])
		{
			if (i != l && base[i] == base[l])
				return ;
			i++;
		}
		l++;
	}
	if (l > 1)
		ft_putnbr_lbase(nb, base, l);
}

// int	main(void)
// {
// 	write(1, "42:", 3);
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n2a:", 4);
// 	ft_putnbr_base(42, "0123456789abcdef");
// 	write(1, "\n-2a:", 5);
// 	ft_putnbr_base(-42, "0123456789abcdef");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "0");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "+-0123456789abcdef");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "\t0123456789abcdef");
// }
