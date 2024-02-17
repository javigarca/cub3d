/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:18:58 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:46:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_isdigit()
 * 
 * DESCRIPTION:
 * 		Check for a digit character. No locale is considered.
 * 
 * RETURN:
 * 		Return nonzero if digit is alphabetic and zero if not.
 * 
 * PARAMS:
 * 		@param c: character to check.
 * 
 * TIPS:
 * 		1. - MAN ASCII
 */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}
