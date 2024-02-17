/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:32:13 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:45:39 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_isascii()
 * 
 * DESCRIPTION:
 * 		Check for an ASCII character. Any between 0 and octal 0177 inclusive.
 * 
 * RETURN:
 * 		Return nonzero if digit is ASCII and zero if not.
 * 
 * PARAMS:
 * 		@param	c: character to check.
 * TIPS:
 * 		1.- NO EXTENDEND ASCII !!!! Only up to 127
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
