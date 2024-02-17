/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:57:35 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/18 17:43:31 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strjoin()
 * 
 * DESCRIPTION:
 * 		Concatenate two strings and return an new fresh string.
 * 
 * PARAMS:
 * 		@param s: string
 * 		@param f: function to be applied.
 * 
 * RETURN:
 * 		New fresh string.
 * 
 * TIPS:
 * 		1. Take care of & inside the fuction.
 */
char	*ft_strjoin(char const *s1, const char *s2)
{
	size_t	dest_len;
	size_t	i;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (0);
	dest = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest != NULL)
	{
		dest_len = ft_strlen(s1);
		i = 0;
		ft_strlcpy(dest, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
		while (s2[i] != '\0')
		{
			dest[dest_len + i] = s2[i];
			i++;
		}
		dest[dest_len + i] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
