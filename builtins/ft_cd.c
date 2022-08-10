/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:11:46 by kos               #+#    #+#             */
/*   Updated: 2022/08/10 19:35:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_input(t_env *env, char *path)
{
	if (ft_strlen(path) == 0 || !ft_strncmp(path, "~", ft_strlen(path)))
	{
		if (!ft_strncmp(get_env_var_value(env, "HOME"), "no", 2))
			printf("minishell: cd: HOME not set\n");
		else
			ft_cd(env, get_env_var_value(env, "HOME"));
	}
	else
		printf("cd: %s: No such file or directory\n", path);
}

void	ft_cd(t_env *env, char *path)
{
	char	*temp;
	char	*temp_cwd;

	temp = 0;
	temp_cwd = 0;
	if (!chdir(path))
	{
		temp = get_env_var_value(env, "PWD");
		set_env_var_value(env, "OLDPWD", temp);
		temp_cwd = getcwd(temp_cwd, PATH_MAX);
		set_env_var_value(env, "PWD", temp_cwd);
	}
	else
		handle_input(env, path);
}
