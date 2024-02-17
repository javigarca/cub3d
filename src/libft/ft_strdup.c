/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:02:09 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strdup()
 * 
 * DESCRIPTION:
 * 		Allocates sufficient memory for a copy of the string s1, does the copy,
 * 		and returns a pointer to it.
 * 
 * PARAMS:
 * 		@param s1: string to be copied.
 * 
 * RETURN:
 *		Pointer to the string.
 * 
 * TIP:
 * 		1. Don't forget to close the array with '\0'
 */

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
