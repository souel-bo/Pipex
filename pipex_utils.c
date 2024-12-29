/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:14:58 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/28 15:54:39 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_check(char **path)
{
	perror("strjoin error");
	free_split(path);
	exit(EXIT_FAILURE);
}

char	*help_check_command(char **path, char *command)
{
	int		i;
	char	*full_path;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		if (!temp)
			ft_check(path);
		full_path = ft_strjoin(temp, command);
		free(temp);
		if (!full_path)
			ft_check(path);
		if ((access(full_path, X_OK)) == 0)
		{
			free_split(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(path);
	return (NULL);
}

char	*check_command(char *envirement, char *command, char **exe)
{
	char	**path;
	char	*full_path;

	path = ft_split(envirement, ':');
	if (!path)
	{
		perror("allocation failed at execute");
		exit(EXIT_FAILURE);
	}
	if (!command)
	{
		write(2, "Permission denied\n", 19);
		free_split(exe);
		free_split(path);
		exit(1);
	}
	if (command && command[0] != '\0' && ft_strchr(command, '/'))
	{
		full_path = check_if_path(command, path);
		return (full_path);
	}
	full_path = help_check_command(path, command);
	return (full_path);
}

void	execute_command(char **envirement, char *command)
{
	char	*path;
	char	**exe;

	exe = ft_split(command, ' ');
	if (!exe)
	{
		perror("allocation failed at execute");
		exit(EXIT_FAILURE);
	}
	path = check_command(find_path(envirement), exe[0], exe);
	if (!path)
		help_execute(exe[0], exe);
	if ((execve(path, exe, envirement)) == -1)
	{
		perror("execution failed");
		free_split(exe);
		free(path);
		exit(EXIT_FAILURE);
	}
}
