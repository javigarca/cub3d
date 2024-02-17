/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:29:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/17 23:59:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define VERSION "0.1.0"
/************************** FOREGROUND COLORS *********************************/
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT   "\x1B[37m"
# define KNON   "\033[0m"
# define KBLA   "\x1b[40m"
/******************************************************************************/
// checks
int	ft_is_valid_arguments(char *arguments[]);
int ft_is_valid_map(const char *filename);

//utils
int	ft_is_valid_filename(const char *filename);
int	ft_count_files(const char *filename);
int	ft_is_valid_file_extension(const char *filename, const char *extension);
char *ft_str_remove_newline(char *str);
int ft_line_all_spaces(const char *line);
#endif