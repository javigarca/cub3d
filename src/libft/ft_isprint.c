/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:36:44 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:03:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_isprint()
 * 
 * DESCRIPTION:
 * 		Check for an printing character.
 * 		Argument as unsigned char or value of EOF.
 * 
 * RETURN:
 * 		Return nonzero if is printable and zero if not.
 * 
 * TIPS:
 * 		1. - FROM SPACE TO .......EXCEPT THE LAST
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (FALSE);
}
