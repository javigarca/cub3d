/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:01:19 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_memcpy()
 * 
 * DESCRIPTION:
 * 		Copies n bytes from memory area src to memory area dst.
 * 		If src and dst overlap, behavior is undefined.
 * 
 * 
 * PARAM:
 * 		@param dst: destination memory.
 * 		@param src: source memory.
 * 		@param   n: number of bytes to be copied. 
 * 
 * RETURN:
 * 		Return original value of dst.
 * 
 * TIPS:
 * 		1. Loop from end to begining
 * 		2. Convert to (char *) and (const char *)
 * 		3. If both, dst and src, are NULL, then return NULL
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_aux;
	char		*dst_aux;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_aux = (char *)dst;
	src_aux = (const char *)src;
	while (n-- > 0)
		*dst_aux++ = *src_aux++;
	return (dst);
}
