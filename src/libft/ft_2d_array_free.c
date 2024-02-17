/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_array_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:11:37 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:03:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Function to free memory from 2d array
 * 
 * @param envs 2d array
 */
void	ft_2d_array_free(char **envs)
{
	int	count;
	int	i;

	count = ft_2d_array_size(envs);
	i = 0;
	while (i < count)
	{
		free(envs[i]);
		i++;
	}
	free(envs);
}
