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
	char	c;
	int		l;
	int		i;

	l = 0;
	while (base[l])
	{
		if (base[l] == '-')
			return ;
		if (base[l] == '+')
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
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(2147483647, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "01");
// 	write(1, "\n", 1);
// 	return (0);
// }
