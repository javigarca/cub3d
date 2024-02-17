/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:29:56 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

static char	*ft_generate_heredoc_file(char *heredoc);
static char	*ft_heredoc_filename(int number);
static void	ft_show_heredoc_error(char *heredoc);

/**
 * @brief 
 * 
 * @param input 
 * @return char* 
 */
char	*ft_expand_heredoc(char *input)
{
	char	*txt_output;

	txt_output = ft_generate_heredoc_file(input);
	free(input);
	return (txt_output);
}

/**
 * @brief 
 * 
 * @param heredoc 
 * @return char* 
 */
static char	*ft_generate_heredoc_file(char *heredoc)
{
	static int	file_num = 0;
	char		*txt_out;
	int			fd;
	char		*input;

	txt_out = ft_heredoc_filename(file_num);
	file_num++;
	fd = open(txt_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (42)
	{
		input = readline(KBLU">");
		if (input == NULL)
		{
			ft_show_heredoc_error(heredoc);
			break ;
		}
		if (strncmp(heredoc, input, strlen(input)) == 0)
			if (ft_strlen(heredoc) == ft_strlen(input))
				break ;
		write(fd, input, strlen(input));
		write(fd, "\n", 1);
	}
	ft_colorirze(2, KNRM);
	close(fd);
	return (txt_out);
}

static char	*ft_heredoc_filename(int number)
{
	char	*txt_out;
	char	*txt_number;

	txt_out = (char *) malloc(25 * sizeof(char));
	ft_strlcpy(txt_out, TMP_PATH, 25);
	ft_strlcat(txt_out, "/", 25);
	ft_strlcat(txt_out, PRE_HEREDOC, 25);
	if (number < 1000)
		ft_strlcat(txt_out, "0", 25);
	if (number < 100)
		ft_strlcat(txt_out, "0", 25);
	txt_number = ft_itoa(number);
	ft_strlcat(txt_out, txt_number, 25);
	free(txt_number);
	ft_strlcat(txt_out, ".txt", 25);
	return (txt_out);
}

static void	ft_show_heredoc_error(char *heredoc)
{
	ft_colorirze(2, KRED);
	ft_putstr_fd("minishell: ", 2);
	ft_colorirze(2, KNRM);
	ft_putstr_fd("warning: here-document delimited by end-of-file ", 2);
	ft_putstr_fd("(wanted `", 2);
	ft_putstr_fd(heredoc, 2);
	ft_putstr_fd("')\n", 2);
}
