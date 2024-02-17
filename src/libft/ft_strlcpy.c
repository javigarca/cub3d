/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:10:52 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strlcpy()
 * 
 * DESCRIPTION:
 * 		Copies the src string to dst string. Take the full size of dst buffer
 * 		and guarantee NUL-termination.
 * 
 * PARAMS:
 * 		@param     dst: destination string.
 * 		@param     src: source string.
 * 		@param dstsize: final length (nul termination included).
 * 
 * RETURN:
 * 		Total length tried to create.
 * 
 * TIPS:
 * 		1. Copy while src or dstsize-1 is not found
 * 		2. dts[dstsize] = '\0' always!
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
