/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:49:30 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:51 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		ft_len_nbr(long n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static long		reverse_nb(long n, int len)
{
	long nb;

	nb = 0;
	while (len-- > 0)
	{
		nb = nb * 10 + n % 10;
		n = n / 10;
	}
	return (nb);
}

static	char	*convert_nb(char *dst, long nb, int len, int neg)
{
	int i;

	i = 0;
	if (neg == 1)
		dst[i++] = '-';
	while (i < len)
	{
		dst[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		length;
	long	nb;
	int		neg;

	neg = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		neg++;
	}
	if (nb == 0)
	{
		if (!(dst = malloc(sizeof(*dst) * 2)))
			return (NULL);
		dst[0] = '0';
		dst[1] = '\0';
		return (dst);
	}
	length = ft_len_nbr(nb);
	nb = reverse_nb(nb, length);
	if (!(dst = malloc(sizeof(*dst) * (length + neg + 1))))
		return (NULL);
	return (convert_nb(dst, nb, length + neg, neg));
}
