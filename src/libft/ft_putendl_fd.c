/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:53:01 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:23 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_putendl_fd()
 * 
 * DESCRIPTION:
 * 		Output the string s to the file descriptor fd.
 * 
 * PARAMS:
 * 		@param  s: string to be written
 * 		@param fd: file descriptor.
 * 
 * RETURN VALUE:
 * 		NOTHING
 */

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
