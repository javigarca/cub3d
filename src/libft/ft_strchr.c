/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:32 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strchr()
 * 
 * DESCRIPTION:
 * 		Locates the first occurrence of c(converted to a char) in the string s.
 * 		The terminating null character is considered part of string.
 * 
 * RETURN:
 * 		Return a pointer to the located character o NULL if does not appear.
 * 
 * PARAMS:
 * 		@param s: string
 * 		@param c: char to find.
 * TIP:
 * 		1. '\0' is also considered, so len + 1
 */

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1)
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	return ((char *) NULL);
}
