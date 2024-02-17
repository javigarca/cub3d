/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:30:42 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:29 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strnstr()
 * 
 * DESCRIPTION:
 * 		Locates the first occurrence of null terminated string needle in haystack
 * 
 * PARAMS:
 * 		@param haystack: original string.
 * 		@param   needle: string to be found.
 * 		@param      len: maximum length find.
 * 
 * RETURN:
 * 		If needle is empty, haystack is returned.
 * 		If needle occurs nowhere in haystack, NULL is returned.
 * 		Otherwise a pointer to the first character of the occurrence.
 * 
 * TIPS:
 * 		1. - 
 * 	
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	void	*output;

	i = 0;
	if (ft_strlen(needle) == 0)
	{
		output = (char *)(haystack);
		return (output);
	}
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (len < ft_strlen(needle) || ft_strlen(haystack) == 0)
		return (NULL);
	if (len == 0)
		return ((char *)(haystack));
	while ((i < len - ft_strlen(needle) + 1) && len > 0)
	{
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
		{
			output = (char *)(haystack + i);
			return (output);
		}
		i++;
	}
	return (NULL);
}
