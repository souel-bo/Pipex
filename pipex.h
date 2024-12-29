/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:08:51 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/29 18:25:57 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

char	*find_path(char **envirement);
char	*check_command(char *env, char *command, char **exe);
void	execute_command(char **envirement, char *command);
void	ft_open_output(char *argument);
void	ft_open_input(char *argument);
void	child_process2(char *argument, char **env, int *pipe_fd, char *file);
void	child_process(char *argument, char **env, int *pipe_fd, char *name);
void	ft_perror(char *msg);
void	free_split(char **split);
char	*check_if_path(char *command, char **path);
char	*help_check_command(char **path, char *command);
void	*help_execute(char *msg, char **exe);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
