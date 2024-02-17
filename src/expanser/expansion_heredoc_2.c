/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_heredoc_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:54:16 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:32 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

static int	ft_heredoc_count_files(void);
static void	ft_delete_files(char **files);

/**
 * @brief function to delete auxiliar files used in heredoc
 * 
 */
char	**ft_generar_files(int *contador, DIR *d)
{
	char			**files;
	struct dirent	*dir;

	files = (char **)malloc(sizeof(char *) * (ft_heredoc_count_files() + 2));
	if (d)
	{
		files[0] = ft_strdup(RM_PATH);
		dir = readdir(d);
		while (dir != NULL)
		{
			if (ft_strncmp(dir->d_name, PRE_HEREDOC, strlen(PRE_HEREDOC)) == 0)
			{
				files[*contador] = (char *)malloc(255 * sizeof(char));
				ft_strlcpy(files[*contador], TMP_PATH, 255);
				ft_strlcat(files[*contador], "/", 255);
				ft_strlcat(files[*contador], dir->d_name, 255);
				*contador = *contador + 1;
			}
			dir = readdir(d);
		}
	}
	closedir (d);
	files[*contador] = NULL;
	return (files);
}

void	ft_delete_heredoc_files(void)
{
	DIR				*d;
	int				contador;
	char			**files;

	d = opendir(TMP_PATH);
	contador = 1;
	files = ft_generar_files(&contador, d);
	if (contador > 1)
		ft_delete_files(files);
	contador = 0;
	ft_2d_array_free(files);
}

/**
 * @brief 
 * 
 * @return int 
 */
static int	ft_heredoc_count_files(void)
{
	DIR				*d;
	int				contador;
	struct dirent	*dir;

	contador = 0;
	d = opendir(TMP_PATH);
	if (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			if (ft_strncmp(dir->d_name, PRE_HEREDOC, \
				ft_strlen(PRE_HEREDOC)) == 0)
				contador = contador +1;
			dir = readdir(d);
		}
		closedir(d);
		return (contador);
	}
	return (0);
}

static void	ft_delete_files(char **files)
{
	pid_t	child_pid;
	int		child_status;
	pid_t	tpid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(RM_PATH, files, (char **) NULL) == -1)
			(void)files;
	}
	else
	{
		do
			tpid = wait(&child_status);
		while
			(tpid != child_pid);
	}
}
