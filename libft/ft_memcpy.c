/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:09:46 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/09 13:38:01 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
