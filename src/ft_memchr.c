/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:52:52 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:55 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *p;

	p = (char *)s;
	while (n--)
		if (*p++ == c)
			return (--p);
	return (0);
}
