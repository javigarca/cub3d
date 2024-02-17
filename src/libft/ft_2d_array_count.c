/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_array_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:02:27 by xamayuel          #+#    #+#             */
/*   Updated: 2022/04/27 11:05:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function to count the number of elements of a 2D array
 * 		  with last elemnent pointing NULL
 * 
 * @param envs 2D array
 * @return int number of elements in array
 */
int	ft_2d_array_size(char **envs)
{
	int	count;

	count = 1;
	while (envs[count] != NULL)
		count++;
	return (count);
}
