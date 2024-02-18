/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:27:35 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 14:50:52 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * @brief Prints an error message to the console in a formatted way.
 *
 * This function takes an error message string and displays it with formatting
 * likely using terminal color codes. It then returns `FALSE`.
 *
 * @param error_text Pointer to a null-terminated character string
 				     containing the error message.
 *
 * @return `FALSE`, indicating an error condition.
 */
int	ft_show_error(const char *error_text)
{
	printf(KRED"Error\n");
	printf(KWHT"CUBE3D:");
	printf("%s \n", error_text);
	return (FALSE);
}
