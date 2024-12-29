/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:48:45 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/26 15:13:06 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_output(char *argument)
{
	int	fd;

	fd = open((const char *)argument, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("failed to open output file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup failed at output");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	ft_open_input(char *argument)
{
	int	fd;

	fd = open((const char *)argument, O_RDONLY);
	if (fd == -1)
	{
		perror("failed to open input file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("dup failed at input");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	child_process2(char *argument, char **env, int *pipe_fd, char *file)
{
	ft_open_output(file);
	close(pipe_fd[1]);
	if ((dup2(pipe_fd[0], 0)) == -1)
	{
		perror("dup failed at parent process in the pipe");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	execute_command(env, argument);
}

void	child_process(char *argument, char **env, int *pipe_fd, char *name)
{
	ft_open_input(name);
	close(pipe_fd[0]);
	if ((dup2(pipe_fd[1], 1)) == -1)
	{
		perror("dup failed at child process in the pipe");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	execute_command(env, argument);
}
