/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:19:10 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:03:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_memmove()
 * 
 * DESCRIPTION:
 * 		Copies n bytes from memory area src to memory area dst.
 * 		Memory areas can overlap.
 * 
 * RETURN:
 * 		Return a pointer to dest.
 * 
 * PARAMS:
 * 		@param dest: destination memory.
 * 		@param  src: source memory.
 * 		@param    n: bytes to be copied.
 * 
 * TIPS:
 * 		1. If dest = src or n = 0 return Dest
 * 		2. Equal to memcpy excetp when dest>src and overlap can occurs.
 * 		3. If overlap, copy in reverse mode.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest2 == src2 || n == 0)
		return (dest);
	if (dest > src && (size_t)(dest - src) < n)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
