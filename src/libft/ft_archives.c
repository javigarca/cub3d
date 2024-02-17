/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:41:58 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/14 17:42:24 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
static char	*archive_name(void)
{
	int		apid;
	char	*path;
	char	*name;

	apid = getpid();
	name = ft_itoa(apid);
	path = ft_strjoin("/tmp/", name);
	free(name);
	return (path);
}
*/

int	ft_error_w(int status, int fds)
{
	int		fd;
	char	*stat;

	if (fds)
		fd = open("/tmp/minitmppipe.log", O_RDWR | O_CREAT, 0777);
	else
		fd = open("/tmp/minitmp.log", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		return (-1);
	stat = ft_itoa(status);
	ft_strcat(stat, "\n");
	write(fd, stat, ft_strlen_g(stat));
	close(fd);
	free (stat);
	return (0);
}

int	ft_error_r(int fds)
{
	int		fd;
	int		status;
	char	*status_char;

	status = 0;
	if (fds)
		fd = open("/tmp/minitmppipe.log", O_RDWR);
	else
		fd = open("/tmp/minitmp.log", O_RDWR);
	if (fd < 0)
		return (-1);
	status_char = get_next_line(fd);
	status = ft_atoi((const char *)status_char);
	free(status_char);
	close(fd);
	return (status);
}

void	ft_archive_init(void)
{
	if (remove("/tmp/minitmppipe.log") == 0)
		ft_error_w(0, 1);
	if (remove("/tmp/minitmp.log") == 0)
		ft_error_w(0, 0);
}
