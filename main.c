/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:48:51 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/28 13:16:41 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_void(void)
{
	ft_putstr_fd("the correct argument should be : \n", 2);
	ft_putstr_fd("./pipex in_file 'command' 'command' out_file", 2);
	exit(EXIT_FAILURE);
}

static void	ft_pipe(void)
{
	perror("pipe failed");
	exit(EXIT_FAILURE);
}

static void	ft_fork(void)
{
	perror("failed to fork");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **env)
{
	pid_t	process_id;
	int		pipe_fd[2];

	if (argc != 5)
		ft_void();
	if ((pipe(pipe_fd)) == -1)
		ft_pipe();
	process_id = fork();
	if (process_id == -1)
		ft_fork();
	if (process_id == 0)
		child_process(argv[2], env, pipe_fd, argv[1]);
	close(pipe_fd[1]);
	process_id = fork();
	if (process_id == -1)
	{
		perror("failed to fork");
		exit(EXIT_FAILURE);
	}
	if (process_id == 0)
		child_process2(argv[3], env, pipe_fd, argv[4]);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
}
