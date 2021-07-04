/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:56:48 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/04 09:56:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <strings.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	str[] = "";

// 	printf("%d\n", ft_strlen(str));
// 	printf("%lu\n", strlen(str));
// 	return (0);
// }