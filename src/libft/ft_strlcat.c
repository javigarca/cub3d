/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:21:49 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:04:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strlcat()
 * 
 * DESCRIPTION:
 * 		Concatenates the src string to dst string. It will append at most 
 * 		dstsize - strlen(dst) - 1
 * PARAMS:
 * 		@param     dst: destination string.
 * 		@param 	   src: source string.
 * 		@param dstsize: final length (nul-termination included)
 * 
 * RETURN:
 * 		Total length tried to create.
 *
 * COMMENTS:
 * 		Copies int dest+len(dest)  src, with a  size of  dstzice-len(dst). 
 * 		If dstsize-len(dst) <0, nothing is done and return dstsize+len(str)		
 *
 * TIPS:
 * 		1. use ft_strlcpy
 */	

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dest;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize < len_dest)
		return (dstsize + len_src);
	else
	{
		ft_strlcpy(dst + len_dest, src, dstsize - len_dest);
	}
	return (len_dest + len_src);
}
