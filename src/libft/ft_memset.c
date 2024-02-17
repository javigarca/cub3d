/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:47:59 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:22 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_memset()
 * 
 * DESCRIPTION:
 * 		Writes len bytes of value c(converted to unsigned char) to string s.
 * 
 * PARAMAS:
 * 		@param   s: string to be overwrite.
 * 		@param   c: char to write.
 * 		@param len: number of bytes to be written.
 * 
 * RETURN:
 * 		Returns its first argument.
 */

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	cont;

	cont = 0;
	while (cont < len)
	{
		((unsigned char *)s)[cont] = (unsigned char)c;
		cont++;
	}
	return (s);
}
