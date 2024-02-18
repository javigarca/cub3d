/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:56:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 11:48:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * @brief Checks the validity of program arguments.
 *
 * This function verifies that the provided arguments comply with the program's
 * expectations. It performs two checks:
 *
 * 1. **File extension:** Ensures the provided filename (second argument)
 *    has the correct ".cub" extension.
 * 2. **Filename existence:** Confirms that the specified filename is a valid
 *    and readable file.
 *
 * If either of these checks fails, the function returns `FALSE`. Otherwise,
 * it returns `TRUE`, indicating valid arguments.
 *
 * @param arguments Array of program arguments.
 *
 * @return `TRUE` if arguments are valid, `FALSE` otherwise.
 */
int	ft_is_valid_input_file(char *arguments[])
{
	if (ft_is_valid_file_extension(arguments[1], ".cub") == FALSE)
		return (FALSE);
	if (ft_is_valid_filename(arguments[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}


