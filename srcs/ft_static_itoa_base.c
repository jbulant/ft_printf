/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 02:57:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/12 06:24:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

static size_t	nblen(unsigned int n, int base)
{
	size_t len;

	len = 0;
	while ((n /= base) > 0)
		len++;
	return (len);
}

char			*ft_static_itoa_base(int n, int base)
{
	static char		charset[17] = "0123456789abcdef";
	static char		str[67];
	unsigned int	nb;
	size_t			len;

	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	len = nblen(nb, base) + ((n >= 0 || base != 10) ? 1 : 2);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	str[--len] = charset[nb % base];
	while ((nb /= base))
		str[--len] = charset[nb % base];
	return (str);
}
