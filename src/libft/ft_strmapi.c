/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:33:23 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/18 17:45:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strmapi()
 * 
 * DESCRIPTION:
 * 		Applies the function 'f' to all the characters of the string to
 * 		create a new fresh string with malloc.
 * 
 * PARAMS:
 * 		@param s: string.
 * 		@param f: function to be applied.
 * 
 * RETURN:
 *		The fresh string. NULL is allocation fails
 *
 * TIPS:
 * 		1. - Protect malloc
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	if (s == NULL || !f)
		return (0);
	out = (char *)malloc(ft_strlen(s) + 1);
	if (out != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			out[i] = f(i, s[i]);
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
