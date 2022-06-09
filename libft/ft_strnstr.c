/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:12:24 by mmaric            #+#    #+#             */
/*   Updated: 2021/11/29 10:50:40 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	postion;

	if (*tofind == '\0')
		return ((char *)str);
	postion = ft_strlen((char *)tofind);
	while (*str != '\0' && len-- >= postion)
	{
		if (*str == *tofind && ft_memcmp(str, tofind, postion) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
