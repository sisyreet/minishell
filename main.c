/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:21:04 by kos               #+#    #+#             */
/*   Updated: 2022/08/10 21:09:21 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
/* temp */
int	define_command(char *cmd, t_env *env)
{
	if (!ft_strncmp("env", cmd, 3))
	{
		print_env(env);
		return (0);
	}
	if (!ft_strncmp("echo ", cmd, 5) && ft_strlen(cmd) > 5)
	{
		ft_echo(&cmd[5], 0);
		return (0);
	}
	if (!ft_strncmp("pwd", cmd, 3))
	{
		ft_pwd(env);
		return (0);
	}
	if (!ft_strncmp("cd", cmd, 2))
	{
		ft_cd(env, &cmd[3]);
		return (0);
	}
	if (!ft_strncmp("unset", cmd, 5))
	{
		ft_unset(env, &cmd[6]);
		return (0);
	}
	if (!ft_strncmp("exit", cmd, 4))
	{
		ft_exit(env, "123");
		return (0);
	}
	if (!ft_strncmp("export", cmd, 6))
	{
		ft_export(env, "yo", "you!");
		return (0);
	}
	return (1);
}
/* temp */

int	ft_readline(char **envp, t_env *env)
{
	char	*line;

	line = 0;
	using_history();
	while (1)
	{
		line = readline("minishell> ");
		if (line > 0)
		{
			if (define_command(line, env))
				printf("minishell: command not found: %s\n", line);
			add_history(line);
		}
		free (line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		ft_error_message("malloc failed!");
	(void)argc;
	(void)argv;
	get_env_vars(envp, env);
	ft_readline(envp, env);
	return (0);
}
