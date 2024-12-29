/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:14:34 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/28 15:14:49 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

char	*find_path(char **envirement)
{
	int	i;

	i = 0;
	while (envirement[i])
	{
		if ((ft_strncmp(envirement[i], "PATH=", 5)) == 0)
			return (envirement[i] + 5);
		i++;
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*check_if_path(char *command, char **path)
{
	char	*cmd;

	if ((access(command, X_OK)) == 0)
	{
		free_split(path);
		cmd = command;
	}
	else
	{
		cmd = NULL;
		free_split(path);
	}
	return (cmd);
}

void	*help_execute(char *msg, char **exe)
{
	ft_perror("command not found : ");
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_split(exe);
	exit(EXIT_FAILURE);
}
