/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:14:38 by kgulfida          #+#    #+#             */
/*   Updated: 2024/11/06 10:04:50 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_and_exit(t_cmd *cmd, int status)
{
	free_env_list(cmd->env);
	free_env_list(cmd->exp);
	free_fd(cmd);
	full_free(cmd);
	if (cmd)
		free(cmd);
	exit(status);
}

void	ft_exit(t_cmd *cmd)
{
	char	*arg;
	int		status;

	printf("exit\n");
	if (cmd->pipe_count == 1)
	{
		if (cmd->command[0][1] == NULL)
			ft_free_and_exit(cmd, 0);
		arg = remove_quotes(cmd, cmd->command[0][1]);
		if (!ft_isnumeric(arg))
		{
			executer_error_2(cmd->command[0], " numeric argument required");
			free(arg);
			ft_free_and_exit(cmd, 255);
		}
		if (cmd->command[0][2] != NULL)
		{
			free(arg);
			executer_error_2(cmd->command[0], " too many arguments");
			cmd->status = 1;
			return ;
		}
		status = ft_atoi(arg) % 256;
		free(arg);
		ft_free_and_exit(cmd, status);
	}
}
