/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:29:24 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:14 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_isdigit()
 * 
 * DESCRIPTION:
 * 		Check for a digit or alphabetic character. No locale is considered.
 * 
 * RETURN:
 * 		Return nonzero if digit is alphabetic or digit and zero if not.
 * 
 * PARAMA:
 * 		@param c: char to be check.
 * 
 * TIPS:
 * 		1. - Use ft_isalpha and ft_isdigit
 */

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (FALSE);
}
