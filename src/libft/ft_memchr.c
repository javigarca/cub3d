/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:15:01 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/18 17:26:06 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_memchr()
 * 
 * DESCRIPTION:
 * 		Locates the first occurrence of c (converted to unsigned char) in
 * 		string s.
 * 
 * RETURN:
 * 		Return a pointer to the byte located, or NULL if not exists.
 * 
 * PARAMS:
 * 		@param s: string s
 * 		@param c: char to be found
 * 		@param n: number of chars to be compared
 * 
 * TIPS:
 * 		1. - Convert to unsigned char both string and char
 * 		2. - return converted to void
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*txt;
	unsigned char	cc;
	size_t			i;

	if (n == 0)
		return (NULL);
	txt = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (txt[i] == cc)
			return ((void *)(txt + i));
		i++;
	}
	return (NULL);
}
